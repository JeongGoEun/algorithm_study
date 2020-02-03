#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int N, MIN = 987654321, dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int nextIdx[4] = { 3,2,0,1 };
bool visited[101][101][4];	//[기준y][기준x][방향]-상,하,좌,우
vector<vector<int>> map;
struct Robot {
	// 기준, 끝, 시간
	int sy, sx, ey, ex, dir, time;
};

bool move(int nsy, int nsx, int ney, int nex, int i) {
	// cout << nsy << ", " << nsx << " -- " << ney << ", " << nex << endl;
	// cout << map[nsy][nsx] << "   " << map[ney][nex] << endl << endl;
	// 기준 범위 검사
	if (nsy<0 || nsx<0 || nsy>=N || nsx>=N) return false;

	// 끝 범위 검사
	if (ney<0 || nex<0 || ney>=N || nex>=N) return false;

	//다 0일때만 가능
	if (map[nsy][nsx] || map[ney][nex]) return false;

	return true;
}

void bfs() {
	queue<Robot> q;
	//0,1기준 왼쪽방향
	visited[0][1][2] = true;
	q.push({ 0,1,0,0,2,0 });

	while (!q.empty()) {
		Robot cur = q.front();
		q.pop();

		cout << cur.sy << ", " << cur.sx << " --- " << cur.ey<<", "<<cur.ex << endl;

		if ((cur.sy == N-1 && cur.sx == N-1) || (cur.ey == N-1 && cur.ex == N-1)) {
			MIN = cur.time < MIN ? cur.time : MIN;
			continue;
		}

		// 직선 이동확인
		for (int i = 0; i < 4; i++) {
			int nsy = cur.sy + dy[i], nsx = cur.sx + dx[i];
			int ney = cur.ey + dy[i], nex = cur.ex + dx[i];
			
			if (move(nsy, nsx, ney, nex, i)) {
				if (!visited[nsy][nsx][cur.dir]) {
					//cout << nsy << ", " << nsx << " -- " << ney << ", " << nex << endl;

					visited[nsy][nsx][cur.dir] = true;
					q.push({ nsy, nsx, ney, nex, cur.dir, cur.time + 1 });
				}
			}
		}

		// 회전 이동 확인
		if (cur.dir <= 1) {
			//상,하 -> 왼, 오로 이동가능하면 됨
			for (int i = 2; i <= 3; i++) {
				int nsy = cur.sy + dy[i], nsx = cur.sx + dx[i];
				int ney = cur.ey + dy[i], nex = cur.ex + dx[i];
				if (move(nsy, nsx, ney, nex, i)) {
					if (!visited[cur.sy][cur.sx][i]) {
						visited[cur.sy][cur.sx][i] = true;
						q.push({ cur.sy, cur.sx, nsy, nsx, i, cur.time + 1 });
					}
				}
			}
		}
		else {
			//좌,우 -> 상, 하로 이동가능하면 됨
			for (int i = 0; i <= 1; i++) {
				int nsy = cur.sy + dy[i], nsx = cur.sx + dx[i];
				int ney = cur.ey + dy[i], nex = cur.ex + dx[i];
				if (move(nsy, nsx, ney, nex, i)) {
					if (!visited[cur.sy][cur.sx][i]) {
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