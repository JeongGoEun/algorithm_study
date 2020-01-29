#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[100][100], dy[3] = { -1,0,0 }, dx[3] = { 0,-1,1 },MIN=987654321,ans=0;
bool visited[100][100];
struct Node {
	int y, x, d;
};
void simulate(Node e) {
	int y = e.y, x = e.x, d = e.d,start=e.x;
	int cnt = 0;
	while (y < 99) {
		//현재에서 왼쪽,오른쪽 확인
		y++;
		cnt++;
		if (x - 1 >= 0 && map[y][x - 1] == 1) {
			while (true) {
				if (x - 1 < 0 || map[y][x - 1] == 0)break;
				x--;
				cnt++;
			}
		}
		else if (x + 1 < 100 && map[y][x + 1] == 1) {
			while (true) {
				if (x + 1 >= 100 || map[y][x + 1] == 0)break;
				x++;
				cnt++;
			}
		}
	}
	if (MIN > cnt) {
		ans = start;
		MIN = cnt;
	}
	else if (MIN == cnt) {
		ans = ans < start ? start : ans;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	int N = 10;
	while (N--) {
		int t = 0;
		cin >> t;
		Node e;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 100; i++) {
			// 모든 출발점에 대하여
			if (map[0][i] == 1) {
				simulate({ 0,i,0 });
			}
		}
		cout << "#" << t << " " << ans << "\n";
		memset(visited, 0, sizeof(visited));
		ans = 0;
		MIN = 987654321;
	}
	return 0;
}

/*
문제점1
- 모든 출발점에서 검사해야 하니까 코드를 변경해야 함
- cnt++은 위로, 좌우로 갈때도 해줘야하니까 x를 변경해주는 부분에서도 증가해야함

문제점2
- 계속x값이 99가 나와서 이상했는데 최소값 !갱신!을 안해줌..(MIN값 업데이트 line:34)
*/