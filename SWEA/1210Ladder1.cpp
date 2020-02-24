#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[100][100], dy[3] = { -1,0,0 }, dx[3] = {0,-1,1};
bool visited[100][100];
struct Node {
	int y, x, d;
};
int bfs(Node e) {
	queue<Node> q;

	q.push(e);
	visited[e.y][e.x] = true;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		if (cur.y == 0) {
			return cur.x;
		}
		bool check = true;

		// 0일땐 - 좌우만 보면 됨, 1,2일땐 - 상하만 보면 됨
		if (cur.d == 0) {
			for (int i = 1; i <= 2; i++) {
				int nx = cur.x + dx[i];
				if (nx < 0 || nx >= 100 || visited[cur.y][nx]) continue;
				if (map[cur.y][nx] == 1) {
					q.push({ cur.y,nx,i });
					visited[cur.y][nx] = true;
					check = false;
				}
			}
			//양쪽 아무것도 없을 때
			if (check) {
				int ny = cur.y + dy[0];
				if (ny < 0 || visited[ny][cur.x]) continue;
				if (map[ny][cur.x] == 1) {
					q.push({ ny,cur.x,0 });
					visited[ny][cur.x] = true;
				}
			}
		}
		else {
			int ny = cur.y + dy[0];
			if (ny < 0 || visited[ny][cur.x]) continue;
			if (map[ny][cur.x] == 1) {
				q.push({ ny,cur.x,0 });
				visited[ny][cur.x] = true;
				check = false;
			}
			//상,하 아무것도 없을 때
			if (check) {
				int nx = cur.x + dx[cur.d];
				if (nx < 0 || nx >= 100 || visited[cur.y][nx]) continue;
				if (map[cur.y][nx] == 1) {
					q.push({ cur.y,nx,cur.d });
					visited[cur.y][nx] = true;
				}
			}
		}
	}
}
int simulate(Node e) {
	int y = e.y, x = e.x, d = e.d;
	while (y > 0) {
		//현재에서 왼쪽,오른쪽 확인
		y--;
		if (x - 1 >= 0 && map[y][x - 1] == 1) {
			while (true) {
				if (x-1 < 0 || map[y][x-1] == 0)break;
				x--;
			}
		}
		else if (x + 1 < 100 && map[y][x + 1] == 1) {
			while (true) {
				if (x+1 >= 100 || map[y][x+1] == 0)break;
				x++;
			}
		}
	}
	return x;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	int N = 10;
	while (N--) {
		int t = 0;
		cin >> t;
		Node e;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
				if (map[i][j] == 2) {
					e = { i,j,0 };
				}
			}
		}
		cout <<"#"<<t<<" "<< simulate(e) << "\n";
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
/*
풀이
- bfs로 한번에 성공했지만 시뮬레이트로 할 수 있을 것 같아서 도전
	-> 무조건 위로 가니까 y좌표는 신경쓰지 말고 x좌표만 신경써보자
- bfs : 0.01770s, 시뮬 : 0.01611s

문제점1
- 시뮬로 할 때, 쉬운 문제였는데 조건을 따질때 주의하자
			while (true) {
				//옳은 코드
				if (x-1 < 0 || map[y][x-1] == 0)break;
				x--;

				//틀린 코드
				x--;
				if (x < 0 || map[y][x] == 0)break;
			}
			이 부분에서 x를 먼저 이동시키고 그 부분에서 map을 확인하기 때문에
			가야되지 않을 부분(0인 부분)을 가게된다.
			이동할때 주의하길
*/