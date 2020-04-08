#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T, N, M, K;
// 상태배열 : 1 - 대기, 2-활성화, 3- 죽음
int status[500][500], maxLife[500][500];
bool visited[500][500];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
struct Node {
	int y, x, life, lifeCnt, status;
	bool first;
};
vector<Node> cell, alive, birth;

int bfs() {
	int rtn = 0;
	for(int time=1;time<=K;time++) {
		for (int i = 0; i < cell.size(); i++) {
			Node n = cell[i];
			if (status[n.y][n.x] != 3) {
				
				if (status[n.y][n.x] == 1) {
					// 대기상태이고, 시간이 다 됐다면
					if (n.lifeCnt == time) {
						status[n.y][n.x] = 2;
						n.status = 2;
						n.lifeCnt = time + n.life;
						alive.push_back(n);
					}
				}
				else if (status[n.y][n.x] == 2) {
					if (n.first) {
						n.first = false;
						for (int i = 0; i < 4; i++) {
							int ny = dy[i] + n.y;
							int nx = dx[i] + n.x;
							// 비어있고, 더 작은 값이라면
							if (status[ny][nx] == 0 && maxLife[ny][nx] < n.life) {
								status[ny][nx] = 1;
								maxLife[ny][nx] = n.life;
								birth.push_back({ ny,nx,n.life,n.life + time,1,true });
							}
						}
					}
					if (n.lifeCnt == time) {
						status[n.y][n.x] = 3;
						n.status = 3;
					}
				}
			}
		}
		for (int i = 0; i < cell.size(); i++) {
			if (cell[i].status != 3) {
				alive.push_back(cell[i]);
			}
		}
		for (int i = 0; i < birth.size(); i++) {
			if(maxLife[birth[i].y][birth[i].x] == birth[i].life)
				alive.push_back(birth[i]);
		}
		swap(cell, alive);
		alive.clear();
		birth.clear();
	}
	
	return rtn;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		queue<Node> wq, aq;

		cin >> N >> M >> K;
		int tmp = 0, max = 0;
		// 1000의 중간지점부터 시작
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tmp;
				if (tmp > 0) {
					cell.push_back({ i + 200, j + 200, tmp, tmp * 2, true, 0 });
					status[i + 200][j + 200] = 1;
				}
			}
		}
		int ans = bfs();
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}

/*
처음 생각
- set으로 좌표를 string으로 변환해서 해결하려고 했다 -> 500 * 500으로도 충분히 가능하다
- waitQ, activeQ를 놓고 각각 대기할 때, 실행할 때를 고려했다
	-> 각 큐에서 겹치는 부분이 있었음
	-> 동시에 들어가고자 할 때의 처리가 없었음

풀이
- vector를 두고 1초마다 순회하며 진행
- 각 상태를 저장하는 배열과, time+life를 진행하여 바꿔줌
- maxLife라는 최대 값으로 마지막에 최대값을 가진 애들만 cell벡터에 넣어줘야 했다.

*/