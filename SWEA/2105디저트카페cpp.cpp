#include<iostream>
#include<cstring>
using namespace std;
int T, N, MAX=0;
int map[20][20], dy[4] = { 1,1,-1,-1 }, dx[4] = { 1,-1,-1,1 };
bool visited[20][20], checkDesert[101];
void print() {
	cout << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}
void dfs(int cy, int cx, int sy, int sx, int cnt, int d) {
	int next = 2;
	if (d == 3) {
		// 마지막 방향이면 계속 그 방향을 유지 해야한다
		next = 1;
	}

	// 현재 방향, 다음 방향으로 갈 수 있는지 확인
	for (int i = 0; i < next; i++) {
		int nd = d + i;
		int ny = cy + dy[nd], nx = cx + dx[nd];
		// 좌표 범위 확인 실수..
		if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
			// 시작점과 같아졌을 때

			if (ny == sy && nx == sx) {
				//print();
				MAX = cnt > MAX ? cnt : MAX;
				return;
			}
			// 방문하지 않았고, 같은 디저트가 없다면
			if (!visited[ny][nx] && !checkDesert[map[ny][nx]]) {
				visited[ny][nx] = true;
				checkDesert[map[ny][nx]] = true;
				dfs(ny, nx, sy, sx, cnt + 1, nd);
				visited[ny][nx] = false;
				checkDesert[map[ny][nx]] = false;
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		MAX = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 맨처음은 다시 돌아와야 되니까 체크 안함
				visited[i][j] = true;
				checkDesert[map[i][j]] = true;
				dfs(i, j, i, j, 1, 0);
				visited[i][j] = false;
				checkDesert[map[i][j]] = false;
			}
		 }

		// for testcase
		/*int ty = 0, tx = 2;
		visited[ty][tx] = true;
		checkDesert[map[ty][tx]] = true;
		dfs(ty, tx, ty, tx, 1, 0);*/

		MAX = MAX == 0 ? -1 : MAX;

		cout << "#" << t << " " << MAX << "\n";
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
/*
생각1
ooo	
o.o
ooo
//.을 기준으로 4방향을 생각해서 처리 -> 시작점이 아니라서 헷갈림


생각2
o0o
3o1
o2o
- 자기 자신을 기준으로 방향을 생각
- 방향이 0이면 오른쪽 아래, 1이면 왼쪽 아래, 2이면 왼쪽 위, 3이면 오른쪽 위

*/