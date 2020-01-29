#include<iostream>
#include<vector>
using namespace std;
int N, dy[4] = { 0,-1,0,1 }, dx[4] = { 1,0,-1,0 };
//0,1,2,3, -> ��, ��, ��, ��
bool visited[101][101], adj[101][101];
struct Node {
	int x, y, d, g;
};
Node curves[21];
vector<int> generation[21];
void setGeneration(int idx) {
	Node cur = curves[idx];

	// 0����, 1���� ����
	generation[idx].push_back(cur.d);
	generation[idx].push_back((cur.d + 1) % 4);

	// 2���� ~ cur.g���� ����
	for (int i = 2; i <= cur.g; i++) {
		// �������� ����+1 % 4
		for (int j = generation[idx].size() - 1; j >= 0; j--) {
			generation[idx].push_back(((generation[idx][j] + 1) % 4));
		}
	}
	/*for (int i = 0; i< generation[idx].size(); i++) {
		cout << generation[idx][i] << " ";
	}
	cout << endl;*/
}
void move(int idx) {
	int y = curves[idx].y, x = curves[idx].x;
	//������ �湮 ǥ��
	visited[y][x] = true;

	for (int i = 0; i < generation[idx].size(); i++) {
		int d = generation[idx][i];
		int ny = y + dy[d];
		int nx = x + dx[d];

		visited[ny][nx] = true;
		y = ny;
		x = nx;
	}

}
int countRect() {
	int rtn = 0;
	
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) {
				rtn++;
			}
		}
	}
	return rtn;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;

	int x = 0, y = 0, d = 0, g = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >>d >> g;

		// make generation direction
		generation[i].push_back(d);
		for (int j = 0; j < g; j++) {
			for (int k = generation[i].size() - 1; k >= 0; k--) {
				generation[i].push_back((generation[i][k] + 1) % 4);
			}
		}

		//���� visitedüũ
		visited[y][x] = true;
		for (int j = 0; j < generation[i].size(); j++) {
			y += dy[generation[i][j]];
			x += dx[generation[i][j]];
			visited[y][x] = true;
		}

		//setGeneration(i);
		//move(i);


	}

	cout<<countRect();

	return 0;
}

/*
�Ǽ�����
- ������ �ִ�� N�� �ƴ϶� 100�̿��� �Ѵ�. �׷��� �ڲ� map�˻��Ҷ� continue����(��е��� ������)

01.08 �ؾ��� ��
- �� ������ �̾��� �ִ� �� üũ(�ܼ��� ������ �ϸ� ���̾����� ������)
- ���п� ���� �簢�� ���� ī��Ʈ

�ǹ���
- �簢���� ����� �� 4���� ���� �� visited�̴��� ������ ���̾������� �� �ִµ� �̰� ��� ó��..
	-> �簢�� ����� �ƴ϶� �巡�� Ŀ�꿡 ���ϴ� ���̸� �����̿�

�ذ���
- �ʹ� �Լ��� �Ἥ �򰥷ȴ� - �ڵ带 �����丵 �غ��� �Ѵ�
- ������ ������� ���� ���� ������ �Ĳ��ϰ� �а� �ڼ���ڸ��� �����ϱ�
- �Լ��� �Ⱦ��� ���� ���� �ڵ带 ����� ���� �� �ִ�
*/