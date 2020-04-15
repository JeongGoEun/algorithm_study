#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int turn[20][20],magnet[4][8],T,K;	//N : 0, S: 1
void print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << magnet[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void turnMagnet(int idx, int flag) {
	int tmp = 0;
	if (flag == 1) {
		tmp = magnet[idx][7];
		for (int i = 7; i > 0; i--) {
			magnet[idx][i] = magnet[idx][i - 1];
		}
		magnet[idx][0] = tmp;
	}
	else {
		tmp = magnet[idx][0];
		for (int i = 0; i < 7; i++) {
			magnet[idx][i] = magnet[idx][i + 1];
		}
		magnet[idx][7] = tmp;
	}
}
int getAnswer() {
	for (int i = 0; i < K; i++) {
		int curIdx = turn[i][0], curFlag = turn[i][1];
		vector<pair<int, int>> v;
		// 현재인덱스 ~ 0
		
		int tmpFlag = curFlag;
		for (int j = curIdx; j > 0; j--) {
			//현재 자석과 다음 자석 검사
			if (magnet[j][6] != magnet[j - 1][2]) {
				//서로 반대일 때
				//cout << j-1 << " 1to " << tmpFlag *-1 << endl;

				v.push_back({ j - 1, tmpFlag * -1 });
				tmpFlag *= -1;
			}
			else {
				break;
			}
		}

		// 현재 인덱스 ~ 끝
		tmpFlag = curFlag;
		for (int j = curIdx; j < 3; j++) {
			//현재 자석과 다음 자석 검사
			if (magnet[j][2] != magnet[j + 1][6]) {
				//서로 반대일 때
				//cout << j + 1 << " 2to " << tmpFlag * -1 << endl;

				v.push_back({ j + 1, tmpFlag * -1 });
				tmpFlag *= -1;
			}
			else {
				break;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			//cout << v[i].first << " to " << v[i].second << endl;
			turnMagnet(v[i].first, v[i].second);
		}
		//print();
		turnMagnet(curIdx, curFlag);

		//print();
	}
	int rtn = 0;
	for (int i = 0; i < 4; i++) {
		if (magnet[i][0]==1) {
			rtn += (int)pow(2, i);
			//cout << rtn << endl;
		}
	}
	return rtn;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> K;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnet[i][j];
			}
		}
		for (int i = 0; i < K; i++) {
			cin >> turn[i][0] >> turn[i][1];
			turn[i][0] -= 1;
		}
		int ans = getAnswer();
		cout << "#" << t << " " << ans << "\n";

		memset(turn, 0, sizeof(turn));
		
	}
	return 0;
}