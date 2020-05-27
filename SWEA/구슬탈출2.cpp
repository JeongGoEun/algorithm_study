#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int N, M, MIN = 987654321;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
char map[10][10];
bool visited[11][11][11][11];
struct Node {
	int y, x;
};
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

		}
	}
}
int bfs(Node R, Node B) {
	queue<pair<Node, Node>> q;
	q.push({ R,B });
	visited[R.y][R.x][B.y][B.x] = true;
	int time = 0;
	while (!q.empty()) {
		if (time >= 10) break;

		// 동시 이동을 위해서 size만큼 돌려준다
		int size = q.size();
		while (size--) {
			Node r = q.front().first, b = q.front().second;
			q.pop();
			//cout << r.y << ", " << r.x << ", " << b.y << ", " << b.x << endl;
			for (int i = 0; i < 4; i++) {
				int nry = r.y, nrx = r.x, nby = b.y, nbx = b.x;
				bool rFlag = false, bFlag = false;

				//빨강 이동
				while (true) {
					nry += dy[i];
					nrx += dx[i];
					if (map[nry][nrx] == '#') {
						nry -= dy[i];
						nrx -= dx[i];
						break;
					}
					else if (map[nry][nrx] == 'O') {
						rFlag = true;
						break;
					}
				}

				//파랑 이동
				while (true) {
					nby += dy[i];
					nbx += dx[i];
					if (map[nby][nbx] == '#') {
						nby -= dy[i];
						nbx -= dx[i];
						break;
					}
					else if (map[nby][nbx] == 'O') {
						bFlag = true;
						break;
					}
				}

				//이미 방문
				if (visited[nry][nrx][nby][nbx]) continue;
				//파랑이 먼저 갔다면
				if (bFlag && !rFlag)continue;
				//둘다 동시에 빠졌다면
				if (rFlag && bFlag)continue;
				//빨강만 빠졌다면
				if (rFlag && !bFlag) return time + 1;

				//둘다 만나지 않았을 때
				if (nry == nby && nrx == nbx) {
					//둘이 위치가 같다면 - 순서조정(더 많이 온 애가 뒤에 있어야 한다)
					if (abs(nry - r.y) + abs(nrx - r.x) < abs(nby - b.y) + abs(nbx - b.x)) {
						nby -= dy[i];
						nbx -= dx[i];
					}
					else {
						nry -= dy[i];
						nrx -= dx[i];
					}
				}
				//cout << nry << ", " << nrx << ", " << nby << ", " << nbx << endl<<endl;

				visited[nry][nrx][nby][nbx] = true;
				q.push({ { nry,nrx }, { nby,  nbx } });

			}
		}
		time++;
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M;
	string tmp;
	//input
	int ry=0, rx=0, by=0, bx=0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			map[i][j] = tmp[j];
			if (map[i][j] == 'R') {
				ry = i; rx = j;
			}
			else if (map[i][j] == 'B') {
				by = i; bx = j;
			}
		}
	}

	cout << bfs({ ry,rx }, { by,bx });

	return 0;
}
/*
문제1
- 미리 방문할 때 기존 맵의 처리는 어떻게 해야하는지
=> 우선 #과 O만 생각한 후(R,B위치는 무시한다), R과 B의 위치에 따라 처리를 해주자

생각1
- 고정된 것(벽, 입구)에 대해 접근하는 방법
- R과 B는 계속 움직인다 - 특정 좌표를 visited로 만들어서 하자
	- 이동할 때마다 이동과정을 .으로 바꾸고 visited설정하는건 비효율적
	- 그 위치에서 이동을 한 적이 있는지만 확인하고 R,B는 고려하지 않으면서 처리하는것이 중요한 과정이었따.
*/