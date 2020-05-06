#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T, N, M, C, MAX;
int map[10][10];
bool visited[10][10];

void getMax(int y, int x, int cnt, int curC, int sum) {
	// 기저사례 - 무게 초과 되었을 때, M개 다 채웠을 때
	if (curC > C) return;
	MAX = max(MAX, sum);
	if (cnt == M) return;

	// 현재 벌꿀을 채취하거나, 안하거나
	getMax(y, x + 1, cnt + 1, curC + map[y][x], sum + (map[y][x] * map[y][x]));
	getMax(y, x + 1, cnt + 1, curC, sum);
}

int dfs(int y ,int x) {
	//벌통1 - 현재 위치에서 M만큼 연속되게 방문
	for (int i = 0; i < M; i++) {
		visited[y][x + i] = true;
	}

	// 현재 위치에서 최대 구함
	MAX = 0;
	getMax(y, x, 0, 0, 0);
	int costA = MAX;
	int costB = 0;

	// 벌통2의 최대 구함
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (!visited[i][j]) {
				MAX = 0;
				getMax(i, j, 0, 0, 0);
				costB = max(MAX, costB);
			}
		}
	}

	return costA + costB;
}

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				ans = max(ans, dfs(i, j));
			}
		}
		cout << "#" << t << " " << ans << "\n";

		//초기화
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
}
// dfs + 백트래킹 - 채취하거나, 그렇지 않거나
/*
생각1
- dfs + 시뮬로 생각(각 행에 대해서 2개의 조합 후 각 벌통의 최대값을 구하는 문제)
	=> 각 벌통의 최대값을 구하려면 또 dfs로 전체 조합을 구해야 한다고 생각했다
	=> 백 트래킹을 활용해서 각 벌통 당 최대를 구해야 한다.

*/