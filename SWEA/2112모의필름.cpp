#include<iostream>
#include<cstring>
using namespace std;
int D, W, K, map[14][21], MIN = 987654321;
bool visited[14];	//13장의 막 A,B
void changeCell(int y, int flag, int cmap[14][21]) {	//막, A or B
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
					// 새로운 곳이 K이상 볼 수 없다면
					break;
				}
				prev = map[i][j];
				cnt = 1;
			}
		}
		// !!하나의 열이라도 빠지면 안된다
		if (!flag) {
			return false;
		}
	}
	return true;
}
void dfs(int idx, int cnt) {
	// !!cnt가 현재 MIN값 보다 작으면 가지치기 가능
	if (cnt >= MIN) {
		return;
	}

	// 다 본거임
	if (idx > D) {
		return;
	}

	// 현재 상태 확인
	if (getCell()) {
		MIN = MIN > cnt ? cnt : MIN;
		return;
	}

	// 그냥 갈 때
	dfs(idx+1, cnt);

	int cmap[21] = { 0, };
	copyMap(map[idx], cmap);

	//A로 바꿀 때
	changeCell(idx, 0, map);
	dfs(idx+1, cnt + 1);

	//B로 바꿀 때
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
문제
- 흠 시간초과가 난다. 가지치기 할곳은 왠만하면 다 해준 것 같은데
(line54, 36)
- **처음 짠 코드는 중복이 가능하다(110(0에서 시작) - 110(1에서 시작))그래서visited로 해주면 당연히 시간초과
		=> index로 처리(그 이전은 고려하지 않도록)

- visited방법은 숫자로 해야 할 조합일때만 사용하기(123,132이런것처럼)

*/