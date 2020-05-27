#include <iostream>
#include <string>
#include<queue>
#include<cstring>
using namespace std;
int N, M, map[1001][1001];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[1001][1001][2];	//좌표, 벽을 부쉈을 때와 안부쉈을 때
struct Node {
	int y, x, block, cnt;
};
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
int bfs() {

	queue<Node> q;
	q.push({ 0,0,0,1 });
	visited[0][0][0] = 1;	//y,x에서 뚫을 수 있는 횟수
	int y = 0, x = 0, cnt=0, block=0;

	while (!q.empty()) {
		Node cur = q.front();	q.pop();
		y = cur.y;
		x = cur.x;
		block = cur.block;
		cnt = cur.cnt;

		if (y == N - 1 && x == M - 1) {
			// 가장 먼저 도착 - 가장 먼저 최소
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			//cout << "위치  "<<ny << ", " << nx << endl;
			// 범위 체크
			if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
				//cout << "범위  " << ny << ", " << nx << endl;

				if (map[ny][nx] == 0 && !visited[ny][nx][block]) {
					// 갈수 있고, 방문하지 않았다면
					visited[ny][nx][block] = true;
					q.push({ ny,nx,block, cnt+1 });

				}else if (map[ny][nx] == 1 && block == 0) {
					// 갈 수 없고, 벽을 아직 안뚫었다면
					visited[ny][nx][block+1] = true;
					q.push({ ny,nx, block+1, cnt+1 });
				}
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j]-'0';
		}
	}
	
	cout << bfs();
	return 0;
}
/*
생각1 - dfs
생각2 - 벽돌 하나씩 깨며 bfs

해결 - 좌표에 대한 부순 여부를 확인

* 무조건 시간 복잡도를 먼저 확인
* 가중치가 없는 최단경로는 무조건 bfs
* https://www.acmicpc.net/board/view/27386 참고

*/