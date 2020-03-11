#include<iostream>
#include<cstring>
using namespace std;
int D, W, K, map[14][21], MIN = 987654321;
bool visited[14];	//13���� �� A,B
void changeCell(int y, int flag, int cmap[14][21]) {	//��, A or B
	for (int i = 0; i < W; i++) {
		cmap[y][i] = flag;
	}
}
void copyMap(int map[21], int cmap[21]) {
	for (int j = 0; j < W; j++) {
		cmap[j] = map[j];
	}
}
void printf() {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
bool getCell() {
	int colCnt = 0;
	for (int j = 0; j < W; j++) {
		int prev = map[0][j], cnt = 1;
		bool flag = false;
		for (int i = 1; i < D; i++) {
			if (prev == map[i][j]) {
				cnt++;
				if (cnt == K) {
					colCnt++;
					flag = true;
					break;
				}
			}
			else {
				if (i == D - K + 1) {
					// ���ο� ���� K�̻� �� �� ���ٸ�
					break;
				}
				prev = map[i][j];
				cnt = 1;
			}
		}
		// !!�ϳ��� ���̶� ������ �ȵȴ�
		if (!flag) {
			return false;
		}
	}
	return true;
}
void dfs(int idx, int cnt) {
	// !!cnt�� ���� MIN�� ���� ������ ����ġ�� ����
	if (cnt >= MIN) {
		return;
	}

	// �� ������
	if (idx > D) {
		return;
	}

	// ���� ���� Ȯ��
	if (getCell()) {
		MIN = MIN > cnt ? cnt : MIN;
		return;
	}

	// �׳� �� ��
	dfs(idx+1, cnt);

	int cmap[21] = { 0, };
	copyMap(map[idx], cmap);

	//A�� �ٲ� ��
	changeCell(idx, 0, map);
	dfs(idx+1, cnt + 1);

	//B�� �ٲ� ��
	changeCell(idx, 1, map);
	dfs(idx+1, cnt + 1);

	copyMap(cmap, map[idx]);
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		if (K == 1) {
			MIN = 0;
		}
		else {
			dfs(0, 0);
		}
		cout << "#" << t << " " << MIN << "\n";
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		MIN = 987654321;
	}
	return 0;
}
/*
����
- �� �ð��ʰ��� ����. ����ġ�� �Ұ��� �ظ��ϸ� �� ���� �� ������
(line54, 36)
- **ó�� § �ڵ�� �ߺ��� �����ϴ�(110(0���� ����) - 110(1���� ����))�׷���visited�� ���ָ� �翬�� �ð��ʰ�
		=> index�� ó��(�� ������ ������� �ʵ���)

- visited����� ���ڷ� �ؾ� �� �����϶��� ����ϱ�(123,132�̷���ó��)

*/