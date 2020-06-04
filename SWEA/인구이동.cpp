#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
struct Node {
	int y, x;
};
int N, L, R;
int map[50][50], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[50][50], isOpen[50][50][4];
bool openBoundary();
void bfs(Node n);
void printMap();
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 최대 2천번
	int times = 1,ans=0;
	for (int i = 0; i <= 2000; i++) {
		//printMap();
		// 국경선 열기
		if (!openBoundary()) {
			//아무것도 열린게 없다면
			ans = i;
			break;
		}

		//연합 찾고 인구이동
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				//새로운 연합
				if (!visited[j][k]) {
					bfs({ j, k });
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(isOpen, 0, sizeof(isOpen));
	}
	cout << ans;
	return 0;
}
void bfs(Node n) {
	queue<Node> q;	// 연합 찾기
	vector<Node> v;	// 연합에 속하는 애들 넣기
	q.push(n);
	visited[n.y][n.x] = true;
	int sum = 0;
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		v.push_back(cur);
		sum += map[cur.y][cur.x];

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (visited[ny][nx])continue;

			//방문하지 않았고, 그 방향에 대해 열려있다면
			if (isOpen[cur.y][cur.x][i]) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}

	/*cout << "Union\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].y << ", " << v[i].x << endl;
	}*/
	// 연합된게 있다면
	if (v.size() > 1) {
		for (int i = 0; i < v.size(); i++) {
			map[v[i].y][v[i].x] = sum / v.size();
		}
	}
}
bool openBoundary() {
	bool rtn = false;
	int ny = 0, nx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				ny = i + dy[k];
				nx = j + dx[k];
				//cout << ny << ", " << nx << endl;
				if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

				int dist = abs(map[i][j] - map[ny][nx]);
				if (dist >= L && dist <= R) {
					rtn = true;
					isOpen[i][j][k] = true;
					//cout << "open " << i << ", " << j << ", " << k << endl;
				}
			}
		}
	}
	return rtn;
}
void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl<<endl;
}
