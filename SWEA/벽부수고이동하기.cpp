#include <iostream>
#include <string>
#include<queue>
#include<cstring>
using namespace std;
int N, M, map[1001][1001];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[1001][1001][2];	//��ǥ, ���� �ν��� ���� �Ⱥν��� ��
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
	visited[0][0][0] = 1;	//y,x���� ���� �� �ִ� Ƚ��
	int y = 0, x = 0, cnt=0, block=0;

	while (!q.empty()) {
		Node cur = q.front();	q.pop();
		y = cur.y;
		x = cur.x;
		block = cur.block;
		cnt = cur.cnt;

		if (y == N - 1 && x == M - 1) {
			// ���� ���� ���� - ���� ���� �ּ�
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			//cout << "��ġ  "<<ny << ", " << nx << endl;
			// ���� üũ
			if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
				//cout << "����  " << ny << ", " << nx << endl;

				if (map[ny][nx] == 0 && !visited[ny][nx][block]) {
					// ���� �ְ�, �湮���� �ʾҴٸ�
					visited[ny][nx][block] = true;
					q.push({ ny,nx,block, cnt+1 });

				}else if (map[ny][nx] == 1 && block == 0) {
					// �� �� ����, ���� ���� �ȶվ��ٸ�
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
����1 - dfs
����2 - ���� �ϳ��� ���� bfs

�ذ� - ��ǥ�� ���� �μ� ���θ� Ȯ��

* ������ �ð� ���⵵�� ���� Ȯ��
* ����ġ�� ���� �ִܰ�δ� ������ bfs
* https://www.acmicpc.net/board/view/27386 ����

*/