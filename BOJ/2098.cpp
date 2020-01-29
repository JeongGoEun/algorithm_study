#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
int N, W[17][17],ans;
int dp[17][1 << 16];
//visited를 비트마스크로 표현해보기
int tsp(int cur, int visited) {
	// !! 이미 최소값 구한 적 있다면
	if (dp[cur][visited] != 0) {
		return dp[cur][visited];
	}

	//만약 모든 마을을 방문했다면 => ex. 11111
	if (visited == (1 << N) - 1) {
		// 현재에서 0번까지 갈 수 있다면
		if (W[cur][0] != 0) {
			return W[cur][0];
		}
		return INF;
	}
	int ret = INF;
	for (int i = 0; i < N; i++) {
		// 이미 방문했거나, 가는 경로가 없을 때
		if (visited & (1<<i) || W[cur][i] == 0) continue;

		// 재방문 하여 다시 탐색
		int result = tsp(i, (visited | 1 << i)) + W[cur][i];
		ret = min(ret, result);
	}
	// cur부터 visited까지의 최소값 메모이제이션
	dp[cur][visited] = ret;
	
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	// visited가 1이라는건, ex. 000000001=>맨 첫번째 방문
	cout << tsp(0,1);
	return 0;
}

/*
문제1
- 모든 그래프를 다 순회하는 dfs로 구현했더니 시간초과가 떴다
- 그래서 질문을 봤는데 dp로 해야하는 것 같았다.... dp어려운디
- dfs완전탐색으로 한다면 O(n^n)이라 시간초과가 뜬다


풀이법
- 비트마스크를 이용한 메모이제이션을 구성해야 한다.
- dp로 메모이제이션을 하면 항상 최소값이 유지되기 때문에 이전 값을 사용하는 것

접근이 틀린건 아니지만 dp와 비트마스킹을 사용해야 한다는 것을 몰랐음

**비트마스크**
visited | (1<<i) => i번째에 1추가
visited & (1<<i) => i번째에 1있나 확인
(1<<N)-1 => N개의 비트가 모두 1인지 확인
*/