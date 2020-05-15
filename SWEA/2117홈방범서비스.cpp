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

			// 위에 검사
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

			// 아래 검사
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
				// K가 1일 때
				if (!check && map[i][j] == 1 && M-1>=0) {
					MAX = 1;
					check = true;
				}
			}
		}
		
		// Q.언제까지 구해주는게 좋을까
		// A. K의 크기를 N보다 조금 크게 잡아야 했다. 참고-https://yabmoons.tistory.com/225
		for(K=2;K<=N+1;K++) {
			int cost=0;
			// 운영 비용 구하기
			opCost = (K * K) + (K - 1) * (K - 1);

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int rtn = operateService(i, j);
					// 이익 계산
					if (rtn > 0) {
						cost = (rtn * M) - opCost;

						// 손해를 보지 않았다면
						if (cost >= 0) {
							// 최대 집의 수 갱신
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
문제1
- K값이 무한대 값이기 때문에 언제까지 계산해야 하는지 감이 안왔다.
	=> K가 작다고 생각하고 그때의 최대값을 구해서 적용하면 됐다.
*/