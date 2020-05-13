//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LwsHaD1MDFAXc&categoryId=AV5LwsHaD1MDFAXc&categoryType=CODE
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
struct Node {
	int y, x;
};
int T, N, MIN;
int dy[8] = { -1,-1,-1,0,0,1,1,1 }, dx[8] = { -1,0,1,-1,1,-1,0,1 };
string input;
char map[300][300];
int rmap[300][300];
bool visited[300][300];
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << rmap[i][j] << " ";
		}
		cout << endl;
	}
}
void fixMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '*') {
				rmap[i][j] = -1;
			}
			else {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int ny = i + dy[k], nx = j + dx[k];
					if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
						if (map[ny][nx] == '*') {
							cnt++;
						}
					}
				}
				rmap[i][j] = cnt;
			}
		}
	}
	//print();
}
void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y,x });
	visited[y][x] = true;

	while (!q.empty()) {
		Node cur = q.front();	q.pop();
		for (int k = 0; k < 8; k++) {
			int ny = cur.y + dy[k], nx = cur.x + dx[k];
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				// �ֺ� �湮�ߴٰ� Ȯ��
				if (!visited[ny][nx]) {
					visited[ny][nx] = true;
					// 0�̸� �ٽ� �־ Ȯ���ϱ�
					if (rmap[ny][nx] == 0) {
						q.push({ ny,nx });
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> input;
			for (int j = 0; j < input.size(); j++) {
				map[i][j] = input[j];
			}
		}

		fixMap();
		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && rmap[i][j]==0) {
					bfs(i, j);
					ans++;
				}
			}
		}
		
		//������� ���� �� ��
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j] && rmap[i][j] != -1) {
					ans++;
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";

		//�ʱ�ȭ
		memset(visited, 0, sizeof(visited));

	}
	return 0;
}

/*
����1
- 300*300�� Ŭ�� ������ ���� dfs�� �ϸ� �ð��ʰ��� �� �� ����.
	-> �������� �ֵ��� ���� ó���ϴ� ����� ���÷����� ������ �� ����.

Ǯ��
- 8������ ��� ���� 0�� ������ ���������� ������
- 8������ ��� ���� 0�� �ƴ϶�� �ѹ��� Ŭ������ ó���Ǿ�� �Ѵ�. -> ������ ���ø� �����ϱ�
=> 0�� �ֵ��� ã�� ���������� �۶߸���+1 -> �Ŀ� ���� �ֵ��� �� +1

�����ؼ� �ɷ��� ���� ������ �� ����..
*/