#include<iostream>
#include<string>
using namespace std;
int N, M,ans;
bool arr[50][50],res[50][50];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			arr[i][j]=s[j]-'0';
		}
	}

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			res[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-2; j++) {
			if (arr[i][j] != res[i][j]) {
				for (int k = i; k <= i + 2; k++) {
					for (int l = j; l <= j + 2; l++) {
						arr[k][l] = !arr[k][l];
					}
				}
				ans++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] != res[i][j]) {
				ans = -1;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
풀이
- 왼쪽 위를 바꿀 수 있는건 왼쪽, 위 순서일때만 바꿀 수 있다
=> 현재 고를 수 있는 최적의 방법(바꿔야 한다는 것)
*/