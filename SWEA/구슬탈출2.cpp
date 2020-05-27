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

		// ���� �̵��� ���ؼ� size��ŭ �����ش�
		int size = q.size();
		while (size--) {
			Node r = q.front().first, b = q.front().second;
			q.pop();
			//cout << r.y << ", " << r.x << ", " << b.y << ", " << b.x << endl;
			for (int i = 0; i < 4; i++) {
				int nry = r.y, nrx = r.x, nby = b.y, nbx = b.x;
				bool rFlag = false, bFlag = false;

				//���� �̵�
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

				//�Ķ� �̵�
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

				//�̹� �湮
				if (visited[nry][nrx][nby][nbx]) continue;
				//�Ķ��� ���� ���ٸ�
				if (bFlag && !rFlag)continue;
				//�Ѵ� ���ÿ� �����ٸ�
				if (rFlag && bFlag)continue;
				//������ �����ٸ�
				if (rFlag && !bFlag) return time + 1;

				//�Ѵ� ������ �ʾ��� ��
				if (nry == nby && nrx == nbx) {
					//���� ��ġ�� ���ٸ� - ��������(�� ���� �� �ְ� �ڿ� �־�� �Ѵ�)
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
����1
- �̸� �湮�� �� ���� ���� ó���� ��� �ؾ��ϴ���
=> �켱 #�� O�� ������ ��(R,B��ġ�� �����Ѵ�), R�� B�� ��ġ�� ���� ó���� ������

����1
- ������ ��(��, �Ա�)�� ���� �����ϴ� ���
- R�� B�� ��� �����δ� - Ư�� ��ǥ�� visited�� ���� ����
	- �̵��� ������ �̵������� .���� �ٲٰ� visited�����ϴ°� ��ȿ����
	- �� ��ġ���� �̵��� �� ���� �ִ����� Ȯ���ϰ� R,B�� ������� �����鼭 ó���ϴ°��� �߿��� �����̾���.
*/