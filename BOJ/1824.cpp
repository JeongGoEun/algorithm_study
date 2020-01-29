#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<queue>
using namespace std;
struct Node {
	int y, x, d, mem;
};
int T, R, C;
// 0,1,2,3 - ��,��,��,��
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[21][21][16][4];	//y,x,mem,d
char map[21][21];
set<string> s;

bool bfs(Node n) {
	queue<Node> q;
	q.push(n);
	visited[n.y][n.x][n.mem][n.d];

	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		int y = cur.y, x = cur.x, d = cur.d, mem = cur.mem;
		int val = map[y][x];
		if (val == '@') {
			return true;
		}

		if (val == '?') {
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < 0) {
						ny = R - 1;
					}
					else if (ny >= R) {
						ny = 0;
					}
					else if (nx < 0) {
						nx = C - 1;
					}
					else if (nx >= C) {
						nx = 0;
					}

					if (!visited[ny][nx][mem][i]) {
						q.push({ ny,nx,i,mem });
						visited[ny][nx][mem][i] = true;
					}
				}
		}
		else {
			if (val >= '0' && val <= '9') {
				mem = val - '0';
			}
			else {
				switch (val)
				{
				case '<':
					d = 2; 		break;
				case '>':
					d = 3; 		break;
				case '^':
					d = 0;			break;
				case 'v':
					d = 1;			break;
				case '_':
					d = mem == 0 ? 3 : 2;			break;
				case '|':
					d = mem == 0 ? 1 : 0;			break;
				case '+':
					mem = mem == 15 ? 0 : mem + 1;	break;
				case '-':
					mem = mem == 0 ? 15 : mem - 1;	break;
				default:
					break;
				}
			}
			
			// d ���� ���� ��ǥ �ٲٱ�
			y += dy[d];
			x += dx[d];
			if (y < 0) {
				y = R - 1;
			}
			else if (y >= R) {
				y = 0;
			}
			else if (x < 0) {
				x = C - 1;
			}
			else if (x >= C) {
				x = 0;
			}
			if (!visited[y][x][mem][d]) {
				q.push({ y,x,d,mem });
				visited[y][x][mem][d] = true;
			}
		}
	}

	return false;
}

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> R >> C;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> map[i][j];
			}
		}
		bool check = bfs({ 0,0,3,0 });

		if (check)
			cout << "#" << t + 1 << " YES\n";
		else
			cout << "#" << t + 1 << " NO\n";

		//init
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}

/*
2020.01.06
ó�� ������
�ùķ��̼����� �ذ��Ϸ� ������ ?�� ������ �������� 4������ �� ��ȸ�ؾ� �ϴµ�
���� ���� �ѹ� �� �����ؼ� �̰� ó���ϴ� �κ��� �������.
- for������ ������ break�� �Ŵµ� ���⼭ break�� �ƴ϶� ��� ��ȸ�� �ؾ��Ѵ�

�ذ��� => bfs�� ó���ϱ�
��� ������ ���� - ��? bfs�ʱⰪ ó���� �̻��ؼ�
main���� �ٷ� �޸� ���� �������� -> �̰� �ƴ϶� �� ��ġ�� ���ڰ� �޸� ���̶�� ���� ��������� ����
*/