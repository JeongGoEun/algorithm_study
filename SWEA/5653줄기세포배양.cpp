#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T, N, M, K;
// ���¹迭 : 1 - ���, 2-Ȱ��ȭ, 3- ����
int status[500][500], maxLife[500][500];
bool visited[500][500];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
struct Node {
	int y, x, life, lifeCnt, status;
	bool first;
};
vector<Node> cell, alive, birth;

int bfs() {
	int rtn = 0;
	for(int time=1;time<=K;time++) {
		for (int i = 0; i < cell.size(); i++) {
			Node n = cell[i];
			if (status[n.y][n.x] != 3) {
				
				if (status[n.y][n.x] == 1) {
					// �������̰�, �ð��� �� �ƴٸ�
					if (n.lifeCnt == time) {
						status[n.y][n.x] = 2;
						n.status = 2;
						n.lifeCnt = time + n.life;
						alive.push_back(n);
					}
				}
				else if (status[n.y][n.x] == 2) {
					if (n.first) {
						n.first = false;
						for (int i = 0; i < 4; i++) {
							int ny = dy[i] + n.y;
							int nx = dx[i] + n.x;
							// ����ְ�, �� ���� ���̶��
							if (status[ny][nx] == 0 && maxLife[ny][nx] < n.life) {
								status[ny][nx] = 1;
								maxLife[ny][nx] = n.life;
								birth.push_back({ ny,nx,n.life,n.life + time,1,true });
							}
						}
					}
					if (n.lifeCnt == time) {
						status[n.y][n.x] = 3;
						n.status = 3;
					}
				}
			}
		}
		for (int i = 0; i < cell.size(); i++) {
			if (cell[i].status != 3) {
				alive.push_back(cell[i]);
			}
		}
		for (int i = 0; i < birth.size(); i++) {
			if(maxLife[birth[i].y][birth[i].x] == birth[i].life)
				alive.push_back(birth[i]);
		}
		swap(cell, alive);
		alive.clear();
		birth.clear();
	}
	
	return rtn;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		queue<Node> wq, aq;

		cin >> N >> M >> K;
		int tmp = 0, max = 0;
		// 1000�� �߰��������� ����
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> tmp;
				if (tmp > 0) {
					cell.push_back({ i + 200, j + 200, tmp, tmp * 2, true, 0 });
					status[i + 200][j + 200] = 1;
				}
			}
		}
		int ans = bfs();
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}

/*
ó�� ����
- set���� ��ǥ�� string���� ��ȯ�ؼ� �ذ��Ϸ��� �ߴ� -> 500 * 500���ε� ����� �����ϴ�
- waitQ, activeQ�� ���� ���� ����� ��, ������ ���� ����ߴ�
	-> �� ť���� ��ġ�� �κ��� �־���
	-> ���ÿ� ������ �� ���� ó���� ������

Ǯ��
- vector�� �ΰ� 1�ʸ��� ��ȸ�ϸ� ����
- �� ���¸� �����ϴ� �迭��, time+life�� �����Ͽ� �ٲ���
- maxLife��� �ִ� ������ �������� �ִ밪�� ���� �ֵ鸸 cell���Ϳ� �־���� �ߴ�.

*/