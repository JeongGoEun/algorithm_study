#include<iostream>
#include<queue>
#include<cstring>
int map[101][101],N,maxH,minH,MAX=1;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[101][101] = { 0, };

using namespace std;
void bfs(int h, int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (!q.empty()) {
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			//범위 , 방문확인
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
			if (visited[ny][nx])continue;

			if (map[ny][nx] > h) {
				q.push({ ny,nx });
				visited[ny][nx] = true;
			}
		}
	}
}
void print() {
	cout << endl;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			cout << visited[j][k] << " ";
		}
		cout << endl;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	minH = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			// 최대 높이 찾음
			maxH = maxH < map[i][j] ? map[i][j] : maxH;
			minH = minH > map[i][j] ? map[i][j] : minH;
		}
	}
	//cout << minH << ", " << maxH << endl;
	for (int i = minH; i < maxH; i++) {
		int cnt = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] > i && !visited[j][k]) {
					bfs(i, j, k);
					cnt++;
				}
			}
		}
		MAX = MAX < cnt ? cnt : MAX;
		//print();
		//visited초기화
		memset(visited, 0, sizeof(visited));
	}
	
	cout << MAX;
	return 0;
}