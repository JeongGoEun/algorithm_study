//SWEA 모의문제
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
struct Node {	//군집 구조체
	int y,x,cnt, dir;
};

int dy[5] = { 0,-1,1,0,0 }, dx[5] = { 0,0,0,-1,1 };
int info[101][101][3];	//0:sum ,1: dir, 2: MAX
vector<Node> bugs;

int T, N, M, K;
void printMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << info[i][j][0] << "," << info[i][j][1] << " /";
		}
		cout << endl;
	}
	cout << endl;
}
void changeGroup(int time) {

	while (time--){
		//이동
		for (int i = 0; i < bugs.size(); i++) {
			Node cur = bugs[i];
			int ny = cur.y + dy[cur.dir], nx = cur.x + dx[cur.dir];
			if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) {
				info[ny][nx][0] = cur.cnt / 2;
				if (cur.dir == 1 || cur.dir == 3) {
					info[ny][nx][1] = cur.dir + 1;
				}
				else {
					info[ny][nx][1] = cur.dir - 1;
				}

			}
			else {
				info[ny][nx][0] += cur.cnt;
				if (info[ny][nx][2] < cur.cnt) {
					info[ny][nx][2] = cur.cnt;
					info[ny][nx][1] = cur.dir;
				}
			}
		}

		bugs.clear();

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (info[i][j][0] != 0) {
					bugs.push_back({ i,j,info[i][j][0], info[i][j][1] });
				}
			}
		}
		//printMap();
		memset(info, 0, sizeof(info));
	}
}
int getSum() {
	int rtn = 0;
	for (int i = 0; i < bugs.size(); i++) {
		rtn += bugs[i].cnt;
	}
	return rtn;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int y = 0, x = 0, cnt = 0, dir = 0;
			cin >> y >> x >> cnt >> dir;
			bugs.push_back({ y,x,cnt,dir });
		}

		changeGroup(M);
		int ans = getSum();
		cout << "#" << t << " " << ans << "\n";

		//초기화
		bugs.clear();
	}
	return 0;
}
/*
생각1
- 먼저 이동하고 이동한 애들을 벡터에 저장한 후 sum과 dir을 갱신해주었더니 시간초과

*/
