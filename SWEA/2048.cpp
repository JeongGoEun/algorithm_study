#include<iostream>
using namespace std;
int N, originMap[21][21], map[21][21], order[5],MAX=0;
bool visited[5][4];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
void dfs(int depth);
void move(int dir);
void play(int dir);
int getScore();

void print();
void copyMap();

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> originMap[i][j];
		}
	}

	dfs(0);
	cout << MAX;
	return 0;
}
void dfs(int depth) {
	if (depth == 5) {
		copyMap();	//원본 복사

		for (int i = 0; i < 5; i++) {
			move(order[i]);
			play(order[i]);
			move(order[i]);
		}
		int tmp = getScore();
		MAX = MAX < tmp ? tmp : MAX;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!visited[depth][i]) {
			visited[depth][i] = true;
			order[depth] = i;
			dfs(depth + 1);
			visited[depth][i] = false;
		}
	}
}
void move(int dir) {
	int h = 0, w = 0, val = 0;
	if (dir == 0) {
		//위로 다 옮기기
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				if (map[i][j] == 0) {
					for (h = i + 1; h < N; h++) {
						if (map[h][j] != 0) {
							map[i][j] = map[h][j];
							map[h][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
	else if (dir == 1) {
		for (int j = 0; j < N; j++) {
			for (int i = N - 1; i >= 0; i--) {
				if (map[i][j] == 0) {
					for (h = i - 1; h >= 0 ; h--) {
						if (map[h][j] != 0) {
							map[i][j] = map[h][j];
							map[h][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					for (w = j + 1; w < N; w++) {
						if (map[i][w] != 0) {
							map[i][j] = map[i][w];
							map[i][w] = 0;
							break;
						}
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] == 0) {
					for (w = j - 1; w >= 0; w--) {
						if (map[i][w] != 0) {
							map[i][j] = map[i][w];
							map[i][w] = 0;
							break;
						}
					}
				}
			}
		}
	}
	//print();
}
void play(int dir) {
	if (dir == 0) {
		for (int j = 0; j < N; j++) {
			for (int i = 1; i < N; i++) {
				if (map[i][j]!=0 && map[i][j] == map[i - 1][j]) {
					map[i - 1][j] += map[i][j];
					map[i][j] = 0;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int j = 0; j < N; j++) {
			for (int i = N-2; i >= 0; i--) {
				if (map[i][j] != 0 && map[i][j] == map[i + 1][j]) {
					map[i + 1][j] += map[i][j];
					map[i][j] = 0;
				}
			}
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				if (map[i][j]!=0 && map[i][j - 1] == map[i][j]) {
					map[i][j - 1] += map[i][j];
					map[i][j] = 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = N-2; j >= 0; j--) {
				if (map[i][j] != 0 && map[i][j + 1] == map[i][j]) {
					map[i][j + 1] += map[i][j];
					map[i][j] = 0;
				}
			}
		}

	}
	//print();
}
int getScore() {
	int rtn = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0 && rtn < map[i][j]) {
				rtn = map[i][j];
			}
		}
	}
	return rtn;
}

void copyMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = originMap[i][j];
		}
	}
}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}