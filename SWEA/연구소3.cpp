#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int y, x;
};
vector<Node> virus,v;
int map[50][50], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
//바이러스 살아있는지 확인, 바이러스 조합
bool isAlive[50][50], visited[11];	
int N, M,MIN=987654321,emptyCnt;

void dfs(int idx);
void bfs();
void print(int visited[50][50]);

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (map[i][j] == 0) {
				emptyCnt++;
			}
		}
	}
	if (emptyCnt == 0) {
		MIN = 0;
	}
	else {
		dfs(0);
		if (MIN == 987654321)MIN = -1;
	}
	
	cout << MIN;
	return 0;
}
void bfs() {
	bool visited[50][50] = { 0, };
	int cmap[50][50] = { 0, };
	deque<Node> q;
	int ny=0, nx=0, time = 0, cnt=0;
	for (int i = 0; i < v.size(); i++) {
		q.push_back({ v[i].y, v[i].x });
		visited[v[i].y][v[i].x] = true;
	}

	while (!q.empty()) {
		int size = q.size();
		//이미 다 구해졌을 경우
		if (emptyCnt == cnt)break;

		while (size--) {
			Node cur = q.front();
			q.pop_front();
			cmap[cur.y][cur.x] = time;

			for (int i = 0; i < 4; i++) {
				ny = cur.y + dy[i], nx = cur.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
				if (visited[ny][nx])continue;
				if (map[ny][nx] == 1) {
					cmap[ny][nx] = -1;
					continue;
				}

				if (map[ny][nx] == 0) {
					cnt++;	
				}
				q.push_back({ ny,nx });
				visited[ny][nx] = true;
			}
		}
		time++;
	}


	if (emptyCnt != cnt) {
		time = 987654322;
	}
	else {
		if (MIN > time) {
			/*cout << "-------------" << time << "-----------\n";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i].y << ", " << v[i].x << endl;
			}*/
			MIN = MIN > time ? time : MIN;
			//print(cmap);
		}
	}
}
void dfs(int idx) {
	if (v.size() == M) {
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(virus[i]);
			dfs(i);
			visited[i] = false;
			v.pop_back();
		}
	}
}
void print(int visited[50][50]) {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
/*
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int y, x;
};
vector<Node> virus,v;
int map[50][50], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
//바이러스 살아있는지 확인, 바이러스 조합
bool isAlive[50][50], visited[11];
int N, M,MIN=987654321,emptyCnt;

void dfs(int idx);
void bfs();
void print(int visited[50][50]);

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N>>M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (map[i][j] == 0) {
				emptyCnt++;
			}
		}
	}
	if (emptyCnt == 0) {
		MIN = 0;
	}
	else {
		dfs(0);
		if (MIN == 987654321)MIN = -1;
	}

	cout << MIN;
	return 0;
}
void bfs() {
	bool visited[50][50] = { 0, };
	int cmap[50][50] = { 0, };
	deque<Node> q;
	int ny=0, nx=0, time = 0, cnt=0;
	for (int i = 0; i < v.size(); i++) {
		q.push_back({ v[i].y, v[i].x });
		visited[v[i].y][v[i].x] = true;
	}

	while (!q.empty()) {
		int size = q.size();
		//이미 다 구해졌을 경우
		if (emptyCnt == cnt)break;

		while (size--) {
			Node cur = q.front();
			q.pop_front();
			cmap[cur.y][cur.x] = time;

			for (int i = 0; i < 4; i++) {
				ny = cur.y + dy[i], nx = cur.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
				if (visited[ny][nx])continue;
				if (map[ny][nx] == 0) {
					cnt++;
					q.push_back({ ny,nx });
					visited[ny][nx] = true;
				}
				else if (map[ny][nx] == 2) {
					// 바이러스 활성상태에서 다시 한번 돌 수 있도록
					q.push_front({ ny,nx });
					visited[ny][nx] = true;
					size++;
				}
			}
		}
		time++;
	}

	time--;

	if (emptyCnt != cnt) {
		time = 987654322;
	}
	else {
		if (MIN > time) {
			cout << "-------------" << time << "-----------\n";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i].y << ", " << v[i].x << endl;
			}
			MIN = MIN > time ? time : MIN;
			print(cmap);
		}
	}
}
void dfs(int idx) {
	if (v.size() == M) {
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(virus[i]);
			dfs(i);
			visited[i] = false;
			v.pop_back();
		}
	}
}
void print(int visited[50][50]) {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
*/