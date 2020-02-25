#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct Node {
	int y, x;
};
int N, K, map[8][8], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 },ans=0;
bool visited[8][8], kCheck;
vector<Node> v;
void printf() {
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].y << ", " << v[i].x << endl;
	}
}
void dfs(int y, int x, int cnt) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		// 범위 체크, 방문 체크
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;

		// 더 작을 때 - 그냥 들어감
		if (map[y][x] > map[ny][nx]) {
			visited[ny][nx] = true;
			dfs(ny, nx, cnt + 1);
			visited[ny][nx] = false;
		}
		else {
			// 크거나 같을 때 - K만큼 뺀 값이 더 작을 때
			if (!kCheck) {
				for (int i = 1; i <= K; i++) {
					int nh = map[ny][nx] - i;
					if (nh < map[y][x]) {
						kCheck = true;
						map[ny][nx] = nh;
						visited[ny][nx] = true;

						dfs(ny, nx, cnt + 1);

						kCheck = false;
						map[ny][nx] = map[ny][nx] + i;
						visited[ny][nx] = false;
					}
				}
			}
		}
	}
	ans = ans < cnt ? cnt : ans;

}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		int MAX = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] > MAX) {
					v.clear();
					MAX = map[i][j];
				}
				if (map[i][j] == MAX) {
					v.push_back({ i,j });
				}
			}
		}
		
		// 최대 높이 봉우리부터 시작
		for (int i = 0; i < v.size(); i++) {
			visited[v[i].y][v[i].x] = true;
			dfs(v[i].y, v[i].x, 1);
			visited[v[i].y][v[i].x] = false;
		}

		cout << "#" << t << " " << ans << "\n";

		// 초기화 - visited, map, ans, v
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		ans = 0;
		v.clear();
	}
	return 0;
}