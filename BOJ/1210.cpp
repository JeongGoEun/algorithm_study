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

		// 0�϶� - �¿츸 ���� ��, 1,2�϶� - ���ϸ� ���� ��
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
			//���� �ƹ��͵� ���� ��
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
			//��,�� �ƹ��͵� ���� ��
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
		//���翡�� ����,������ Ȯ��
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
Ǯ��
- bfs�� �ѹ��� ���������� �ùķ���Ʈ�� �� �� ���� �� ���Ƽ� ����
	-> ������ ���� ���ϱ� y��ǥ�� �Ű澲�� ���� x��ǥ�� �Ű�Ẹ��
- bfs : 0.01770s, �ù� : 0.01611s

������1
- �ùķ� �� ��, ���� �������µ� ������ ������ ��������
			while (true) {
				//���� �ڵ�
				if (x-1 < 0 || map[y][x-1] == 0)break;
				x--;

				//Ʋ�� �ڵ�
				x--;
				if (x < 0 || map[y][x] == 0)break;
			}
			�� �κп��� x�� ���� �̵���Ű�� �� �κп��� map�� Ȯ���ϱ� ������
			���ߵ��� ���� �κ�(0�� �κ�)�� ���Եȴ�.
			�̵��Ҷ� �����ϱ�
*/