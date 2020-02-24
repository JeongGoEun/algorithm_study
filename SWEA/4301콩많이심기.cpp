#include<iostream>
#include<cstring>
using namespace std;
int T, N, M, map[1001][1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> M >> N;
		memset(map, 0, sizeof(map));
		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				// 0:심은 곳, 1: 심으면 안되는 곳
				// 가로 검사
				if ((j + 2 < M) && map[i][j] == 0) {
					map[i][j + 2] = 1;
				}
				if ((i + 2 < N) && map[i][j] == 0) {
					map[i + 2][j] = 1;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					ans++;
				}
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}
/*
생각
- 직접 그려봤을 때
TTFFTTFF	이렇게 반복돼서 TTFF와 FFTT배열을 선언한 후 탐색 하려고 시도 -> 틀림
TTFFTTFF
FFTTFFTT
FFTTFFTT
TTFFTTFF
....

- 아예 시뮬레이션으로 돌려보자 -> 통과

배운것
- 가로, 세로 검사에서
범위가 걱정되면 배열을 늘려주는 것도 한 방법(어차피 최대 까지 검사하기 때문에)
그리고 if문에서 map들이 다 같은건 자명하다 -> 검사해줄 필요가 없었다.
if ((j + 2 < M) && (map[i][j] == map[i][j + 2])) -> if ((j + 2 < M) && map[i][j] == 0)

*/