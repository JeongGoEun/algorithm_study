#include <vector>

using namespace std;

int MOD = 20170805;
int L[501][501], U[501][501];//���ʿ���, ������

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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
				// ���ʿ��� ���� ����Ǽ�
				// ���ʿ��� ���� ����Ǽ�
				L[i][j] = (L[i][j-1] + U[i-1][j]) % MOD;
				U[i][j] = (L[i][j - 1] + U[i - 1][j]) % MOD;
			}
			else {
				// ���� ����
				L[i][j] = L[i][j-1] % MOD;
				U[i][j] = U[i-1][j] % MOD;
			}
		}
	}
	return (U[m-1][n] + L[m][n-1]) % MOD;
}

/*
������1
- 0,0���� �����Ѵ� �׷��� ������ ������µ� �׷��ʿ� ������.
-> ���� ������ �Ǹ� dp�迭�� ���Ӱ� ���� map�� ���Ӱ� �����غ���
	dp[1][1] == map[0][0]ó��

������2
- ���� ���� ����� �� memset�� ��������� Ʋ��,,

��
3�����迭 : 24.30ms / 7.37MB
2�����迭 2�� : 25.07ms / 7.36MB


#include <vector>

using namespace std;

int MOD = 20170805;
int dp[501][501][2];	//0 : �¿�, 1: ����

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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
				// ���ʿ��� ���� ����Ǽ�
				// ���ʿ��� ���� ����Ǽ�
				int sum = dp[i][j - 1][0] + dp[i-1][j][1];
				dp[i][j][0] += sum % MOD;
				dp[i][j][1] += sum % MOD;
			}
			else {
				// ���� ����
				dp[i][j][0] += dp[i][j - 1][0] % MOD;
				dp[i][j][1] += dp[i - 1][j][1] % MOD;
			}
		}
	}
	return dp[m][n][0] + dp[m][n][1];
}
*/