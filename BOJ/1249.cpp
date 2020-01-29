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
������
- �� map�� ����� �Է��ϴ��� �������� �Է��ϴ��� ����
	-> �������� �Է��Ѵٸ� scanf("%1d", &map[][])���� ó���ϸ� ��
- dfs�� Ǯ������ �ð��ʰ�.... -> ������� �켱���� ť or BFS�� ó���ߴٰ� �Ѵ�
- bfs�� �غ�����
	- bfs�� ���� ��, �翬�� ���ϴ� ���̱� ������ �������� �������� ã�� �� ������
		=>opt�迭�� �߰��ؼ� ���� ū ������ �ʱ�ȭ�� ���Ѻ��� ���

�ذ�
- opt��� ������ �迭�� ���� �����ϰ� (������ġ+������ġ)�� opt���� ������ġ�� opt������ ������ �� ����=>q�� ����
- opt��� �迭�� ���� �ذ��� �� �־���
- ** ��� ���ذ��� �ּҰ��� ��ã����, ���� �ȵǴ� �ִ밪�� �־ �����غ���
*/