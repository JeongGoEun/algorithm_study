#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100000][4];
int MAX, N, M;

int solution(vector<vector<int>> land)
{
	N = land.size();
	M = land[0].size();
	for (int i = 0; i < M; i++) {
		dp[0][i] = land[0][i];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				if (j != k) {
					dp[i][j] = max(dp[i][j], dp[i - 1][k] + land[i][j]);
					//cout<<dp[i][j]<<", "<<dp[i-1][k]<<", "<<land[i][j]<<endl;
				}
			}
		}
		// cout<<endl;
	}
	for (int i = 0; i < M; i++)
		MAX = MAX < dp[N - 1][i] ? dp[N - 1][i] : MAX;
	return MAX;
}