#include <vector>

using namespace std;

int MOD = 20170805;
int L[501][501], U[501][501];//왼쪽에서, 위에서

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> map) {
	int answer = 0;
	L[1][1] = 1;
	U[1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i-1][j-1] == 1) {
				L[i][j] = 0;
				U[i][j] = 0;
			} else if (map[i-1][j-1] == 0) {
				// 왼쪽에서 오는 경우의수
				// 위쪽에서 오늘 경우의수
				L[i][j] = (L[i][j-1] + U[i-1][j]) % MOD;
				U[i][j] = (L[i][j - 1] + U[i - 1][j]) % MOD;
			}
			else {
				// 각각 따로
				L[i][j] = L[i][j-1] % MOD;
				U[i][j] = U[i-1][j] % MOD;
			}
		}
	}
	return (U[m-1][n] + L[m][n-1]) % MOD;
}

/*
문제점1
- 0,0부터 시작한다 그래서 범위를 따져줬는데 그럴필요 없었다.
-> 범위 걱정이 되면 dp배열을 새롭게 만들어서 map을 새롭게 접근해보자
	dp[1][1] == map[0][0]처럼

문제점2
- 전역 변수 사용할 때 memset을 안해줬더니 틀림,,

비교
3차원배열 : 24.30ms / 7.37MB
2차원배열 2개 : 25.07ms / 7.36MB


#include <vector>

using namespace std;

int MOD = 20170805;
int dp[501][501][2];	//0 : 좌우, 1: 상하

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> map) {
	int answer = 0;
	dp[1][1][0] = 1;
	dp[1][1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i-1][j-1] == 1) {
				dp[i][j][0] = 0;
				dp[i][j][1] = 0;
				continue;
			}

			if (map[i-1][j-1] == 0) {
				// 왼쪽에서 오는 경우의수
				// 위쪽에서 오늘 경우의수
				int sum = dp[i][j - 1][0] + dp[i-1][j][1];
				dp[i][j][0] += sum % MOD;
				dp[i][j][1] += sum % MOD;
			}
			else {
				// 각각 따로
				dp[i][j][0] += dp[i][j - 1][0] % MOD;
				dp[i][j][1] += dp[i - 1][j][1] % MOD;
			}
		}
	}
	return dp[m][n][0] + dp[m][n][1];
}
*/