#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int T, N,M,K,opCost,MAX;
int map[20][20];

//void print() {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cout << visited[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
int operateService(int y, int x) {
	bool visited[20][20] = { 0, };
	int h = K - 1, t = K - 1, ny = 0, nx = 0,cnt=0;
	if (map[y][x] == 1) cnt = 1;
	visited[y][x] = true;
	
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= t; j++) {
			if (i == 0 && j == 0) continue;

			// ���� �˻�
			ny = y + i;
			nx = x + j;
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				if (!visited[ny][nx] && map[ny][nx] == 1) {
					visited[ny][nx] = true;
					cnt++;
				}
			}
			nx = x - j;
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				if (!visited[ny][nx] && map[ny][nx] == 1) {
					visited[ny][nx] = true;
					cnt++;
				}
			}

			// �Ʒ� �˻�
			ny = y - i;
			nx = x + j;
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				if (!visited[ny][nx] && map[ny][nx] == 1) {
					visited[ny][nx] = true;
					cnt++;
				}
			}
			nx = x - j;
			if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
				if (!visited[ny][nx] && map[ny][nx] == 1) {
					visited[ny][nx] = true;
					cnt++;
				}
			}
		}
		t--;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		K = 2;
		MAX = 0;

		bool check = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				// K�� 1�� ��
				if (!check && map[i][j] == 1 && M-1>=0) {
					MAX = 1;
					check = true;
				}
			}
		}
		
		// Q.�������� �����ִ°� ������
		// A. K�� ũ�⸦ N���� ���� ũ�� ��ƾ� �ߴ�. ����-https://yabmoons.tistory.com/225
		for(K=2;K<=N+1;K++) {
			int cost=0;
			// � ��� ���ϱ�
			opCost = (K * K) + (K - 1) * (K - 1);

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int rtn = operateService(i, j);
					// ���� ���
					if (rtn > 0) {
						cost = (rtn * M) - opCost;

						// ���ظ� ���� �ʾҴٸ�
						if (cost >= 0) {
							// �ִ� ���� �� ����
							MAX = MAX < rtn ? rtn : MAX;
						}
					}
				}
			}
		}
		cout << "#" << t << " " << MAX << "\n";
	}

	// for testcase
	/*K = 3;
	N = 5;
	operateService(1, 1);
	print();*/
	return 0;
}
/*
����1
- K���� ���Ѵ� ���̱� ������ �������� ����ؾ� �ϴ��� ���� �ȿԴ�.
	=> K�� �۴ٰ� �����ϰ� �׶��� �ִ밪�� ���ؼ� �����ϸ� �ƴ�.
*/