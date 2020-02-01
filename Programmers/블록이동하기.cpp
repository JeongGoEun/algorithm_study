#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, MIN = 987654321, dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int nextIdx[4] = { 3,2,0,1 };
bool visited[101][101][4];	//[����y][����x][����]-��,��,��,��
vector<vector<int>> map;
struct Robot {
	// ����, ��, �ð�
	int sy, sx, ey, ex, dir, time;
};

bool move(int nsy, int nsx, int ney, int nex, int i) {

	// ���� ���� �˻�
	if (nsy<1 || nsx<1 || nsy>N || nsx>N) return false;

	// �� ���� �˻�
	if (ney<1 || nex<1 || ney>N || nex>N) return false;

	//�� 0�϶��� ����
	if (map[nsy][nsx] || map[ney][nex]) return false;

	return true;
}

void bfs() {
	queue<Robot> q;
	//1,1���� �����ʹ���
	visited[1][1][3] = true;
	q.push({ 1,1,1,2,3,0 });

	while (!q.empty()) {
		Robot cur = q.front();
		q.pop();

		if ((cur.sy == N && cur.sx == N) || (cur.ey == N && cur.ex == N)) {
			MIN = cur.time < MIN ? cur.time : MIN;
			continue;
		}

		// ���� �̵�Ȯ��
		for (int i = 0; i < 4; i++) {
			int nsy = cur.sy + dy[i], nsx = cur.sx + dx[i];
			int ney = cur.ey + dy[i], nex = cur.ex + dx[i];
			if (move(nsy, nsx, ney, nex, i)) {
				if (visited[nsy][nsx][cur.dir]) {
					visited[nsy][nsx][cur.dir] = true;
					q.push({ nsy, nsx, ney, nex, cur.dir, cur.time + 1 });
				}
			}
		}

		// ȸ�� �̵� Ȯ��
		if (cur.dir <= 1) {
			//��,�� -> ��, ���� �̵������ϸ� ��
			for (int i = 2; i <= 3; i++) {
				int nsy = cur.sy + dy[i], nsx = cur.sx + dx[i];
				int ney = cur.ey + dy[i], nex = cur.ex + dx[i];
				if (move(nsy, nsx, ney, nex, i)) {
					if (visited[cur.sy][cur.sx][i]) {
						visited[cur.sy][cur.sx][i] = true;
						q.push({ cur.sy, cur.sx, nsy, nsx, i, cur.time + 1 });
					}
				}
			}
		}
		else {
			//��,�� -> ��, �Ϸ� �̵������ϸ� ��
			for (int i = 0; i <= 1; i++) {
				int nsy = cur.sy + dy[i], nsx = cur.sx + dx[i];
				int ney = cur.ey + dy[i], nex = cur.ex + dx[i];
				if (move(nsy, nsx, ney, nex, i)) {
					if (visited[cur.sy][cur.sx][i]) {
						visited[cur.sy][cur.sx][i] = true;
						q.push({ cur.sy, cur.sx, nsy, nsx, i, cur.time + 1 });
					}
				}
			}
		}

	}

	return;
}

int solution(vector<vector<int>> board) {
	N = board.size();
	map = board;

	bfs();
	return MIN;
}