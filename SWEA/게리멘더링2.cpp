#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int N, MIN = 987654321;
int map[101][101], section[101][101];
void print() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << section[i][j] << " ";
		}
		cout << endl;
	}
}
void checkHorizon(int y, int x, int d1, int d2) {
	section[y][x] = 5;
	for (int i = 0; i <= d1; i++) {
		section[y + i][x - i] = 5;
		section[y + d2 + i][x + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		section[y + i][x + i] = 5;
		section[y + d1 + i][x - d1 + i] = 5;
	}
}
int devideSection(int y, int x, int d1, int d2) {
	vector<int> v(5);
	for (int r = 1; r <= N; r++) {
		bool flag = false;
		for (int c = 1; c <= N; c++) {
			if (section[r][c] == 5) {
				if ((r == y && c == x) || (r == y + d1 + d2 && c == x + d2 - d1)) {
					v[4] += map[r][c];
				}
				else {
					v[4] += map[r][c];
					for (int k = c+1; k <= N; k++) {
						if (section[r][k] != 5) {
							v[4] += map[r][k];
							section[r][k] = 5;
						}
						else {
							v[4] += map[r][k];
							c = k;
							break;
						}
					}
					// 여기서 c=k를 하면 안됐음 - for문에서 int k라고 새로 해줘서 ....
					//c = k;
				}
			}
			else {
				if ((1 <= r && r < y + d1) && (1 <= c && c <= x)) {
					v[0] += map[r][c];
					section[r][c] = 1;
				}
				else if ((1 <= r && r <= y + d2) && (x < c && c <= N)) {
					v[1] += map[r][c];
					section[r][c] = 2;
				}
				else if ((y + d1 <= r && r <= N) && (1 <= c && c < x - d1 + d2)) {
					v[2] += map[r][c];
					section[r][c] = 3;
				}
				else if ((y + d2 < r && r <= N) && (x - d1 + d2 <= c && c <= N)) {
					v[3] += map[r][c];
					section[r][c] = 4;
				}
			}
		}
	}
	sort(v.begin(), v.end());
	int rtn = v[v.size() - 1] - v[0];
	return rtn;
}
void simulate(int d1, int d2) {
	//기준점이 될 수 있는 곳만 좌표 시뮬
	for (int i = 1; i <= N - (d1 + d2); i++) {
		for (int j = 1 + d1; j <= N - d2; j++) {
			//경계선 표시
			memset(section, 0, sizeof(section));
			checkHorizon(i, j, d1, d2);

			int diff = devideSection(i, j, d1, d2);
			MIN = MIN > diff ? diff : MIN;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// d1, d2 시뮬
			simulate(i,j);
		}
	}
	cout << MIN;
	return 0;
}