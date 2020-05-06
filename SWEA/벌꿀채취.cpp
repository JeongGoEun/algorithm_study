#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T, N, M, C, MAX;
int map[10][10];
bool visited[10][10];

void getMax(int y, int x, int cnt, int curC, int sum) {
	// ������� - ���� �ʰ� �Ǿ��� ��, M�� �� ä���� ��
	if (curC > C) return;
	MAX = max(MAX, sum);
	if (cnt == M) return;

	// ���� ������ ä���ϰų�, ���ϰų�
	getMax(y, x + 1, cnt + 1, curC + map[y][x], sum + (map[y][x] * map[y][x]));
	getMax(y, x + 1, cnt + 1, curC, sum);
}

int dfs(int y ,int x) {
	//����1 - ���� ��ġ���� M��ŭ ���ӵǰ� �湮
	for (int i = 0; i < M; i++) {
		visited[y][x + i] = true;
	}

	// ���� ��ġ���� �ִ� ����
	MAX = 0;
	getMax(y, x, 0, 0, 0);
	int costA = MAX;
	int costB = 0;

	// ����2�� �ִ� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (!visited[i][j]) {
				MAX = 0;
				getMax(i, j, 0, 0, 0);
				costB = max(MAX, costB);
			}
		}
	}

	return costA + costB;
}

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> C;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {
				ans = max(ans, dfs(i, j));
			}
		}
		cout << "#" << t << " " << ans << "\n";

		//�ʱ�ȭ
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
	}
}
// dfs + ��Ʈ��ŷ - ä���ϰų�, �׷��� �ʰų�
/*
����1
- dfs + �ùķ� ����(�� �࿡ ���ؼ� 2���� ���� �� �� ������ �ִ밪�� ���ϴ� ����)
	=> �� ������ �ִ밪�� ���Ϸ��� �� dfs�� ��ü ������ ���ؾ� �Ѵٰ� �����ߴ�
	=> �� Ʈ��ŷ�� Ȱ���ؼ� �� ���� �� �ִ븦 ���ؾ� �Ѵ�.

*/