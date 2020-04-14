#include<iostream>
using namespace std;
int N,dp[101];
int main() {
	cin >> N;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++) {
		if (dp[i] == 0) {
			dp[i] = dp[i - 1] + dp[i - 4];
		}
	}
	while (N--) {
		int tmp = 0;
		cin >> tmp;
		cout << dp[tmp] << "\n";
	}
	
	return 0;
}