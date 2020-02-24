#include<iostream>
#include<cstring>
#include<queue>
#define INF 9876543
using namespace std;

int map[101][101],opt[101][101],N,MIN;
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[101][101];
struct Node {
	int y, x;
};
void bfs() {
	queue<Node> q;
	q.push({ 0,0 });
	opt[0][0] = 0;

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

			if (opt[cur.y][cur.x] + map[ny][nx] < opt[ny][nx]) {
				q.push({ ny, nx });
				opt[ny][nx] = opt[cur.y][cur.x] + map[ny][nx];
			}
		}
	}
}

int main() {
	int T = 0;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				opt[i][j] = INF;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &map[i][j]);
			}
		}

		MIN = INF;
		bfs();
		cout <<"#"<<t<<" "<< opt[N-1][N-1]<<"\n";

		memset(visited, 0, sizeof(visited));

	}
	return 0;
}

/*
문제점
- 각 map을 띄어쓰기로 입력하는지 연속으로 입력하는지 주의
	-> 연속으로 입력한다면 scanf("%1d", &map[][])으로 처리하면 됨
- dfs로 풀었더니 시간초과.... -> 사람들은 우선순위 큐 or BFS로 처리했다고 한다
- bfs로 해보겠음
	- bfs로 했을 때, 당연히 더하는 것이기 때문에 이전보다 작은값을 찾을 수 없었음
		=>opt배열을 추가해서 완전 큰 값으로 초기화를 시켜보면 어떨까

해결
- opt라는 최적값 배열을 새로 생성하고 (현재위치+다음위치)의 opt값이 다음위치의 opt값보다 작으면 더 최적=>q에 넣음
- opt라는 배열을 통해 해결할 수 있었음
- ** 계속 더해가서 최소값을 못찾을땐, 말도 안되는 최대값을 넣어서 생각해보자
*/