#include<iostream>
#include<cstring>
using namespace std;
int T, N, ans = 0;
int dp[1000001];
bool nums[10];

void getAnswer() {
	int num = N,cnt=0;
	for (int i = N; i > 1; i--) {	//만들 수 있는 수 중 가장 큰 것
		// 해당 자릿수가 있으면
		while (dp[i] > 0) {	//왜 여기를 while로 잡았을까 - if로 잡아도 되지 않나
			if (num % i == 0) {
				cout << i << ", " << num << endl;
				cnt += 1 + dp[i];
				num /= i;
			}
			else
				break;
		}
		if (num == 1) {
			ans = cnt;
			return;
		}
	}
	ans = -1;
}

void makesNum(int num, int cnt) {
	if (cnt > 7) {
		// 자릿수가 7일 때
		return;
	}
	if (num > N) {
		return;
	}
	if (cnt > 0) {
		// 해당 수 자릿 수 적립
		dp[num] = cnt;
	}
	for (int i = 0; i < 10; i++) {
		if(nums[i])
			makesNum(10 * num + i, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 10; i++) {
			cin >> nums[i];
		}
		cin >> N;

		if (N == 1 && nums[1]) {
			ans = 2;
		}
		else {
			makesNum(0, 0);
			getAnswer();
		}
		cout << "#" << t << " " << ans << "\n";

		memset(dp, 0, sizeof(dp));

	}
	return 0;
}
/*
문제점1 - 나누어 떨어질때 주의(N/10이 아니라 N%10이여야 함)
흠 예외처리가 너무 많다(약수로 하면 다 1일때는 바로 그자릿수+1이 되어야 한다)
-> 검색결과 할 수 있는 수를 최대로 뽑은다음에 계속 비교

풀이
- 우선 완전탐색을 이용해서 최대 숫자까지 구하는 방법은 알겠다

*/