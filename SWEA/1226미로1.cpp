	#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[16][16], T, dy[4] = { -1,1,0,0 }, dx[4] = {0,0,-1,1};
bool visited[16][16];
struct Node {
	int y, x;
};

bool bfs(Node s, Node e) {
	queue<Node> q;
	q.push(s);
	visited[s.y][s.x] = true;

	while (!q.empty()) {
		Node n = q.front();
		q.pop();

		if (n.y == e.y && n.x == e.x) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int ny = n.y + dy[i];
			int nx = n.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= 16 || nx >= 16 || visited[ny][nx])continue;

			if (map[ny][nx] != 1) {
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
	return false;
}
int main() {
	for (int t = 0; t < 10; t++) {
		cin >> T;
		Node s, e;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					s = { i,j };
				}
				else if (map[i][j] == 3) {
					e = { i,j };
				}
			}
		}
		cout << "#" << T << " " << bfs(s,e) << "\n";

		memset(visited, 0, sizeof(visited));
	}
	return 0;
}

/*
풀이
- 간단한 bfs였다. 실수가 있다면 입력을 받을 때 %1d로 받지 않아서 제대로 돌아가지 않은것
- 입력이 연속된 수인지 띄어져 있는 수인지 잘 볼것

*/