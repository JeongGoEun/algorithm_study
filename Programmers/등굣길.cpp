#include <string>
#include <vector>
#include<iostream>
using namespace std;
int N = 1000000007;
int dp[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
	//m: 가로, n: 세로

	// 웅덩이 잠긴곳 표시
	for (int i = 0; i < puddles.size(); i++) {
		int x = puddles[i][0], y = puddles[i][1];
		dp[y][x] = -1;
	}

	dp[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 맨 처음
			if (i == 1 && j == 1) continue;

			// 웅덩이 있는 곳->0으로
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % N;
		}
	}

	return dp[n][m];
}

/*
시도
1: 테스트-4, 효율성 -2

문제점1
- 효율성에서 많이 틀렸는데 dp에 넣어줄 때 N으로 나눈 나머지값을 취해주었더니 효율성 완화
	-> 범위를 넘어가기 때문에 dp배열 자체에서 처리해줘야 한다.


문제점2
- 접근법은 맞았는데 쓸데없는 코드가 있다
ex) 1,1을 1로 잡고 이전과 계속 더해주면 가장자리 부분은 어차피 경로가 1이 된다
	처음에 웅덩이인 곳을 -1처리로 해주려고 했는데 덧셈할때 이상할까봐 isSink를 추가해줬다
	-> 하지만 얘도 그 부분을 만났을 때 0으로 바꿔주고 넘어가면 되는 문제였다.

문제점3
- 처음 코드가 왜 틀렸냐면 가장자리를 다 1로 처리해주면 안됨
	-> 중간에 0이 있으면 그 이후부터는 다 0이여야 하니까
*/