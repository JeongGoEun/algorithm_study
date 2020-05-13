//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc&categoryId=AV5LwsHaD1MDFAXc&categoryType=CODE
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
struct Node {
	int y, x;
};
int T, N, MIN;
int dy[8] = { -1,-1,-1,0,0,1,1,1 }, dx[8] = { -1,0,1,-1,1,-1,0,1 };
string input;
char map[300][300];
int rmap[300][300];
bool visited[300][300];
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << rmap[i][j] << " ";
		}
		cout << endl;
	}
}
void fixMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '*') {
				rmap[i][j] = -1;
			}
			else {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int ny = i + dy[k], nx = j + dx[k];
					if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
						if (map[ny][nx] == '*') {
							cnt++;
						}
					}
				}
				rmap[i][j] = cnt;
			}
		}
	}
	//print();
}
void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty()) {
		Node cur = q.front();	q.pop();
		for (int k = 0; k < 8; k++) {
			int ny = cur.y + dy[k], nx = cur.x + dx[k];
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				// 주변 방문했다고 확인
				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					// 0이면 다시 넣어서 확인하기
					if (rmap[ny][nx] == 0) {
						q.push({ ny,nx });
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			for (int j = 0; j < input.size(); j++) {
				map[i][j] = input[j];
			}
		}

		fixMap();
		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && rmap[i][j]==0) {
					bfs(i, j);
					ans++;
				}
			}
		}
		
		//연쇄되지 못한 것 들
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && rmap[i][j] != -1) {
					ans++;
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";

		//초기화
		memset(visited, 0, sizeof(visited));

	}
	return 0;
}

/*
생각1
- 300*300을 클릭 순서를 위해 dfs로 하면 시간초과가 날 것 같다.
	-> 연속적인 애들을 먼저 처리하는 방법을 떠올렸으면 좋았을 것 같다.

풀이
- 8방향의 모든 합이 0일 때에만 연속적으로 퍼진다
- 8방향의 모든 합이 0이 아니라면 한번의 클릭으로 처리되어야 한다. -> 연속이 나올리 없으니까
=> 0인 애들을 찾아 연속적으로 퍼뜨리고+1 -> 후에 남은 애들은 다 +1

문제해석 능력이 아직 부족한 것 같다..
*/