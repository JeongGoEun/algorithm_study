#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N;
char map[20][20];
void printf() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (char)map[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	string s = "";
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}
	int ans = 987654321;
	// 각 행
	cout << (1 << N) << endl;
	for (int k = 0; k < (1<<N); k++) {	//k행은 뒤집기로 결정
		int tsum = 0;
		for (int j = 0; j < N; j++) {
			int tcnt = 0;

			for (int i = 0; i < N; i++) {
				char cur = map[i][j];
				// 뒤집기로 한 행이라면 - 뒤집기
				if ((1<<i) & k) {
					cur = cur == 'T' ? 'H' : 'T';
				}
				if (cur == 'T') tcnt++;
			}
			// 해당 열을 뒤집는게 이득인지
			tsum += min(tcnt, N - tcnt);
		}
		ans = min(ans, tsum);
	}
	cout << ans;
	return 0;
}
/*
생각
1 - (i,j)기준으로 가로, 세로 T의 갯수를 세고 T의 갯수가 더 많고 그 갯수가 H의 갯수보다 크다면 바꿔줌

풀이
가정 : 모든 행에 대하여 뒤집을지 말지 결정되어 있다면
		-> 열 별로 뒤집을지 말지 결정

line27
- 그냥 for문 변수로 하면 안되고 비트마스킹으로 해야 풀림
*/