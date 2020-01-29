#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool map[101][101][2];   //0 : 기둥, 1 : 보
bool compare(vector<int>& a, vector<int>& b) {
	if (a[0] != b[0]) return a[0] < b[0];
	else if (a[0] == b[0] && a[1] != b[1]) return a[1] < b[1];
	else return a[2] < b[2];
}
void g_check(int x, int y, int s) {
	if (s == 1) {
		if (y == 0 || map[x][y - 1][0] || map[x - 1][y][1]) {
			map[x][y][0] = true;
		}
	}
	else {
		// 양옆에 보 있거나, 위에 아무것도 없을 때
		if (map[x - 1][y + 1][1] || map[x][y + 1][1] || map[x][y][0]) {
			map[x][y][0] = false;
		}
	}
}
void b_check(int x, int y, int s) {
	if (s == 1) {
		if (map[x][y - 1][0] || map[x + 1][y - 1][0] || map[x - 1][y - 1][0] || (map[x - 1][y][1] && map[x + 1][y][1])) {
			map[x][y][1] = true;
		}
	}
	else {
		if (map[x - 1][y][0] && map[x + 1][y][0]) {
			map[x][y][1] = false;
		}
	}
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (int i = 0; i < build_frame.size(); i++) {
		int x = build_frame[i][0], y = build_frame[i][1], f = build_frame[i][2], state = build_frame[i][3];
		if (f == 0) {
			g_check(x, y, state);
		}
		else {
			b_check(x, y, state);
		}
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (map[i][j][0] && map[i][j][1]) {
				answer.push_back({ i,j,0 });
				answer.push_back({ i,j,1 });
			}
			else if (map[i][j][0]) {
				answer.push_back({ i,j,0 });
			}
			else if (map[i][j][1]) {
				answer.push_back({ i,j,1 });
			}
		}
	}
	sort(answer.begin(), answer.end(), compare);

	return answer;
}