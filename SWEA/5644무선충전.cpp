#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
using namespace std;
struct BC {
	int y, x, C, P;
};
vector<int> moveDir[2];	//0:A, 1:B
vector<BC> bcVec;	//for bc vector
vector<pair<int, int>> map[11][11];	//c, p를 가진 맵
int T, M, N;
int dy[5] = { 0,-1,0,1,0 }, dx[5] = { 0,0,1,0,-1 };	//X,상,우,하,좌
bool comp(BC a, BC b) {	//P가 큰 순서대로 설정
	return a.P > b.P;
}
int simulate() {
	int MAX = 0, tmp = 0, p1 = 0, p2 = 0;
	bool flag = true;
	int y1 = 1, x1 = 1, y2 = 10, x2 = 10, sum = 0;
	//cout << A.sum << ", " << B.sum << endl;

	for (int i = 0; i <= M; i++) {

		x1 += dx[moveDir[0][i]];	y1 += dy[moveDir[0][i]];
		x2 += dx[moveDir[1][i]];	y2 += dy[moveDir[1][i]];

		vector<int> v1, v2;

		for (int j = 0; j < bcVec.size(); j++) {
			if (abs(y1 - bcVec[j].y) + abs(x1 - bcVec[j].x) <= bcVec[j].C) {
				v1.push_back(j);
			}
			if (abs(y2 - bcVec[j].y) + abs(x2 - bcVec[j].x) <= bcVec[j].C) {
				v2.push_back(j);
			}
		}

		MAX = 0, p1 = 0, p2 = 0;
		//cout << v1.size() << ", " << v2.size() << endl;

		if (v1.empty() && !v2.empty()) {
			for (int j = 0; j < v2.size(); j++)
				MAX = max(MAX, bcVec[v2[j]].P);
		}
		else if (!v1.empty() && v2.empty()) {
			for (int j = 0; j < v1.size(); j++)
				MAX = max(MAX, bcVec[v1[j]].P);
		}
		else if (!v1.empty() && !v2.empty()) {
			for (int j = 0; j < v1.size(); j++) {
				for (int k = 0; k < v2.size(); k++) {
					// C가 같다면
					int t1 = bcVec[v1[j]].P;
					int t2 = bcVec[v2[k]].P;

					if (v1[j] == v2[k]) {
						// P를 나눠 가져야함
						t1 /= 2;
						t2 /= 2;
					}
					if (MAX < t1 + t2) {
						MAX = t1 + t2;
						//cout << "not same " << p1 << ", " << p2 << endl;
					}
				}
			}
		}

		sum += MAX;
		// y,x로 하면 됨
		//cout << p1 << ", " << p2 << endl;


	}
	return sum;
}
void spread() {
	for (int i = 0; i < bcVec.size(); i++) {
		BC cur = bcVec[i];
		for (int j = 1; j <= 10; j++) {
			for (int k = 1; k <= 10; k++) {
				int d = abs(cur.y - j) + abs(cur.x - k);
				if (d <= cur.C) {
					map[j][k].push_back({ cur.C, cur.P });
				}
			}
		}
	}
	/*for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << map[i][j].size() << " ";
		}
		cout << endl;
	}*/
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// input
		cin >> M >> N;
		// dummy data
		moveDir[0].push_back(0);
		moveDir[1].push_back(0);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < M; j++) {
				int tmp = 0;
				cin >> tmp;
				moveDir[i].push_back(tmp);
			}
		}
		for (int i = 0; i < N; i++) {
			BC tmp;
			cin >> tmp.x >> tmp.y >> tmp.C >> tmp.P;
			bcVec.push_back(tmp);
		}
		//sort(bcVec.begin(), bcVec.end(), comp);
		//// spread BC
		////spread();

		int ans = simulate();
		cout << "#" << t << " " << ans << "\n";

		// init
		moveDir[0].clear();	moveDir[1].clear();
		bcVec.clear();
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				map[i][j].clear();
			}
		}
	}
	return 0;
}