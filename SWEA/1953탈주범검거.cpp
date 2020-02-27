#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, M, R, C, L;
int map[50][50], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[50][50];
struct Node {
	int y, x, time;
};
queue<Node> q;
bool check(int dir, int cur) {
	//cout << next <<"  "<< cur << endl;
	if (dir == 0) {
		if (cur == 1 || cur == 2 || cur == 5 || cur == 6) {
			return true;
		}
	}
	else if (dir == 1) {
		if (cur == 1 || cur == 2 || cur == 4 || cur == 7) {
			return true;
		}
	}
	else if (dir == 2) {
		if (cur == 1 || cur == 3 || cur == 4 || cur == 5) {
			return true;
		}
	}
	else if (dir == 3) {
		if (cur == 1 || cur == 3 || cur == 6 || cur == 7) {
			return true;
		}
	}
	return false;
}
void move(int n, Node cur) {
	int ny = 0, nx = 0;

	if (n == 1) {	//상하좌우
		for (int i = 0; i < 4; i++) {
			ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;

			if (map[ny][nx] != 0 && cur.time + 1 <= L && check(i, map[ny][nx])) {
				q.push({ ny,nx,cur.time + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	else if (n == 2) {	//상하
		for (int i = 0; i < 2; i++) {
			ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;

			if (map[ny][nx] != 0 && cur.time + 1 <= L && check(i, map[ny][nx])) {
				q.push({ ny,nx,cur.time + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	else if (n == 3) {	//좌우
		for (int i = 2; i < 4; i++) {
			ny = cur.y + dy[i], nx = cur.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;
			//cout << ny << ", " << nx << endl;

			if (map[ny][nx] != 0 && cur.time + 1 <= L && check(i, map[ny][nx])) {
				q.push({ ny,nx,cur.time + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	else if (n == 4) {//상우
		for (int i = 0; i < 4; i++) {
			if (i == 1 || i == 2)continue;

			ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;

			if (map[ny][nx] != 0 && cur.time + 1 <= L && check(i, map[ny][nx])) {
				q.push({ ny,nx,cur.time + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	else if (n == 5) {//하우
		for (int i = 0; i < 4; i++) {
			if (i == 0 || i == 2)continue;

			ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;

			if (map[ny][nx] != 0 && cur.time + 1 <= L && check(i, map[ny][nx])) {
				q.push({ ny,nx,cur.time + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	else if (n == 6) {//하좌
		for (int i = 0; i < 4; i++) {
			if (i == 0 || i == 3)continue;

			ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;

			if (map[ny][nx] != 0 && cur.time + 1 <= L && check(i, map[ny][nx])) {
				q.push({ ny,nx,cur.time + 1 });
				visited[ny][nx] = true;
			}
		}
	}
	else if (n == 7) {//상좌
		for (int i = 0; i < 4; i++) {
			if (i == 1 || i == 3)continue;

			ny = cur.y + dy[i], nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])continue;

			if (map[ny][nx] != 0 && cur.time + 1 <= L && check(i, map[ny][nx])) {
				q.push({ ny,nx,cur.time + 1 });
				visited[ny][nx] = true;
			}
		}
	}
}
int bfs() {
	int ans = 0;
	q.push({ R,C,1 });	//한시간부터 시작
	visited[R][C] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		//cout << cur.y << " " << cur.x << " " << cur.time << endl;
		ans++;
		move(map[cur.y][cur.x], cur);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		int answer = bfs();

		cout << "#" << t << " " << answer << "\n";
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));

	}
	return 0;
}
/*
문제1
- visited범위 체크하다가 nx>=N이라그래서 시간 버림,,(nx>=M임)
- 파이프가 연결되어있는 방향위주로 생각(다음이 상 - 다음 모형은 1,2,5,6모형,,,)
	=> 1번 모양에 check함수 조건 추가해주니 맞았음 - 사방으로 무조건 된다고 생각했는데 4,5,6,7같은 모형처럼 변수가 있었다.
*/