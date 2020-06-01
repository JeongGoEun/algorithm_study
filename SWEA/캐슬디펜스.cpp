#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int dy[3] = { 0,-1,0 }, dx[3] = { -1,0,1 };
int N, M, D, map[16][16],cmap[16][16],MAX=0;
bool existHunter[16];
struct Node {
	int y, x;
};
vector<int> hunters;
void dfs(int idx);
Node attack(int idx);
void moveDown();
bool isFinish();
void copyMap();
void printMap();
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//헌터들 조합 만들기
	dfs(0);
	cout << MAX;
	return 0;
}
Node attack(int idx) {
	queue<Node> q;
	bool visited[16][16] = { 0, };
	//cout << N << "--------------" << idx << endl;
	q.push({ N,idx });
	visited[N][idx] = true;

	while (!q.empty()) {
		int size = q.size();
		while (size--) {
			Node cur = q.front();	q.pop();

			//좌, 상, 우로 이동
			for (int i = 0; i < 3; i++) {
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				//cout << ny << "--" << nx << endl;
				if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
				if (visited[ny][nx])continue;

				int dist = abs(N - ny) + abs(idx - nx);
				if (dist <= D) {
					// 가장 왼쪽에 있는 적을 만나면
					if (cmap[ny][nx] == 1) {
						return { ny,nx };
					}
					else {
						q.push({ ny,nx });
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	//공격한게 없을 때
	return { -1,-1 };
}

void dfs(int idx) {
	if (hunters.size() == 3) {
		copyMap();
		int cnt = 0;
		//cout << "start\n";
		//printMap();

		while (!isFinish()) {
			// 동시공격
			vector<Node> death;

			for (int i = 0; i < hunters.size(); i++) {
				Node n = attack(hunters[i]);
				if (n.y != -1 && n.x != -1) {
					//cout << "death " << n.y << ", " << n.x << endl;
					//cout << "from " << hunters[i] << endl << endl;;
					death.push_back(n);
				}
			}
			for (int i = 0; i < death.size(); i++) {
				// 죽이기
				if (cmap[death[i].y][death[i].x] != 0) {
					cnt++;
				}
				cmap[death[i].y][death[i].x] = 0;
			}
			//남은 적 아래로 이동
			//printMap();
			moveDown();
			//printMap();
		}
		//cout << cnt << endl;
		//cout << "finish\n\n";
		MAX = MAX < cnt ? cnt : MAX;
		return;
	}

	for (int i = idx; i < M; i++) {
		if (!existHunter[i]) {
			hunters.push_back(i);
			existHunter[i] = true;
			dfs(i);
			hunters.pop_back();
			existHunter[i] = false;
		}
	}
}
void moveDown() {
	//맨 밑줄은 지우고
	
	int idx = 0;
	for (int j = 0; j < M; j++) {
		for (int i = N - 1; i >= 1; i--) {
			cmap[i][j] = cmap[i-1][j];
		}
	}
	for (int j = 0; j < M; j++) {
		cmap[0][j] = 0;
	}
}
bool isFinish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cmap[i][j] != 0)return false;
		}
	}
	return true;
}
void copyMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cmap[i][j] = map[i][j];
		}
	}
}
void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << cmap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
/*
풀이
- 방향의 우선순위를 잘 고려하자(좌,상,우 -> 최대한 왼쪽부터 진행하도록)
- 동시 공격, 이동 순서 잘 파악하기
- 문제 바르게 읽기

*/