#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct Node {
	int y, x, val;
};
int N, M, T, x, d, k, map[51][51];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[51][51];

void turn(int x, int d, int k);
void erase();
bool bfs(Node n);
void printMap();

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> x >> d >> k;
		for (int j = x; j <= N; j += x) {
			//cout << "turn " << j << endl;
			turn(j, d, k);
		}
		erase();
		//printMap();
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sum += map[i][j];
		}
	}
	cout << sum;
	return 0;
}
void turn(int x, int d, int k) {
	//x원판을 d방향으로 k칸 회전
	// 이런 걸 쓰려면 그냥 전역으로 쓰자..
	int tmp[51] = { 0, };
	if (d == 0) {
		for (int i = 1; i <= M; i++) {
			int idx = i + k;
			if (idx > M) {
				idx -= M;
			}
			tmp[idx] = map[x][i];
		}
	}
	else {
		for (int i = 1; i <= M; i++) {
			int idx = i - k;
			if (idx < 1) {
				idx += M;
			}
			tmp[idx] = map[x][i];
		}
	}
	for (int i = 1; i <= M; i++) {
		map[x][i] = tmp[i];
	}
}
void erase() {
	int val = 0, cnt = 0, sum = 0;
	bool flag = false;

	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!visited[i][j] && map[i][j] != 0) {
				sum += map[i][j];
				cnt++;
				if (bfs({ i,j,map[i][j] })) {
					//하나라도 바뀐게 있다면
					flag = true;
				}
			}
		}
	}

	// 나눌 때 0인지 잘 확인하기
	if (!flag) {
		// 아무것도 지울것이 없을 때
		if (cnt == 0)return;

		double avg = double(sum) / cnt;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] == 0)continue;

				if (map[i][j] > avg) {
					map[i][j] -= 1;
				}
				else if (map[i][j] < avg) {
					map[i][j] += 1;
				}
			}
		}
	}
}
bool bfs(Node n) {
	bool flag = false;
	queue<Node> q;
	q.push(n);
	visited[n.y][n.x] = true;

	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		int ny = 0, nx = 0;
		
		for (int i = 0; i < 4; i++) {
			ny = cur.y + dy[i];
			nx = cur.x + dx[i];

			// !! 행 따로 열 따로 처리해줘야 함
			// !! 가로 - 이어져있음, 세로 - 범위 넘으면 처리 안해줌
			//if (ny<1 || nx<1 || ny>N || nx>M)continue;
			if (ny < 1)continue;
			if (ny > N)continue;
			if (nx < 1)	nx = M;
			if (nx > M)nx = 1;

			if (!visited[ny][nx] && cur.val == map[ny][nx]) {
				map[cur.y][cur.x] = 0;
				map[ny][nx] = 0;

				q.push({ ny,nx,cur.val });
				visited[ny][nx] = true;
				flag = true;
			}

		}
	}
	return flag;
}
void printMap() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}