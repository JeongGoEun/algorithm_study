#include<iostream>
#include<cstring>
using namespace std;
int T, N, MAX=0;
int map[20][20], dy[4] = { 1,1,-1,-1 }, dx[4] = { 1,-1,-1,1 };
bool visited[20][20], checkDesert[101];
void print() {
	cout << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}
void dfs(int cy, int cx, int sy, int sx, int cnt, int d) {
	int next = 2;
	if (d == 3) {
		// ������ �����̸� ��� �� ������ ���� �ؾ��Ѵ�
		next = 1;
	}

	// ���� ����, ���� �������� �� �� �ִ��� Ȯ��
	for (int i = 0; i < next; i++) {
		int nd = d + i;
		int ny = cy + dy[nd], nx = cx + dx[nd];
		// ��ǥ ���� Ȯ�� �Ǽ�..
		if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
			// �������� �������� ��

			if (ny == sy && nx == sx) {
				//print();
				MAX = cnt > MAX ? cnt : MAX;
				return;
			}
			// �湮���� �ʾҰ�, ���� ����Ʈ�� ���ٸ�
			if (!visited[ny][nx] && !checkDesert[map[ny][nx]]) {
				visited[ny][nx] = true;
				checkDesert[map[ny][nx]] = true;
				dfs(ny, nx, sy, sx, cnt + 1, nd);
				visited[ny][nx] = false;
				checkDesert[map[ny][nx]] = false;
			}
		}
	}
	
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		MAX = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// ��ó���� �ٽ� ���ƿ;� �Ǵϱ� üũ ����
				visited[i][j] = true;
				checkDesert[map[i][j]] = true;
				dfs(i, j, i, j, 1, 0);
				visited[i][j] = false;
				checkDesert[map[i][j]] = false;
			}
		 }

		// for testcase
		/*int ty = 0, tx = 2;
		visited[ty][tx] = true;
		checkDesert[map[ty][tx]] = true;
		dfs(ty, tx, ty, tx, 1, 0);*/

		MAX = MAX == 0 ? -1 : MAX;

		cout << "#" << t << " " << MAX << "\n";
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
/*
����1
ooo	
o.o
ooo
//.�� �������� 4������ �����ؼ� ó�� -> �������� �ƴ϶� �򰥸�


����2
o0o
3o1
o2o
- �ڱ� �ڽ��� �������� ������ ����
- ������ 0�̸� ������ �Ʒ�, 1�̸� ���� �Ʒ�, 2�̸� ���� ��, 3�̸� ������ ��

*/