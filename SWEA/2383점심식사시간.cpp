#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int map[10][10];
bool stairState[10];
int T, N, pCnt, MIN, sCnt[10];
struct Node {
	int y, x, val;
};
struct Person {
	int y, x, idx, sIdx, path, activeTime;
	bool isActive;
};
vector<Person> cv;		// 손님 벡터
vector<Node> stairs;	//계단 정보

bool comp(Person p1, Person p2) {
	return p1.path < p2.path;
}

void copyMap(int map[10][10], int cmap[10][10]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cmap[i][j] = map[i][j];
		}
	}
}

void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << cv[i].sIdx << ", " << cv[i].path << endl;
	}
}
int simulate() {
	bool visited[10] = { 0, };
	queue<int> q[2];	//0,1번 계단에 있는 사람

	vector<Person> v;
	for (int i = 0; i < cv.size(); i++) {
		//각 거리 계산
		Node curStair = stairs[stairState[i]];
		///cout << cv[i].y << ", " << cv[i].x << endl;
		cv[i].sIdx = stairState[i];
		cv[i].path = abs(cv[i].y - curStair.y) + abs(cv[i].x - curStair.x);
	}

	//거리 순으로 sorting
	sort(cv.begin(), cv.end(), comp);

	//print();
	
	int outCnt = 0, time = 1;

	// 사람이 다 나갈 때 까지
	while (outCnt < pCnt) {

		// 한칸 앞으로 
		for (int i = 0; i < cv.size(); i++) {
			// 이미 내려가는 사람이라면
			if (cv[i].path < 0) continue;
			cv[i].path--;

			// 계단으로
			if (cv[i].path == 0) {
				if (q[cv[i].sIdx].size() < 3) {
					// 넣을 수 있을 때에만 path--;
					Node cur = stairs[cv[i].sIdx];
					q[cv[i].sIdx].push(cur.val);
				}
				else {
					cv[i].path++;
				}
			}
			//cv[i].path--;
		}

		//계단 이동
		for (int i = 0; i < stairs.size(); i++) {
			int size = q[i].size();
			for (int j = 0; j < size; j++) {
				int p = q[i].front();
				q[i].pop();
				p--;
				if (p == 0) {
					outCnt++;
				}
				else {
					q[i].push(p);
				}
			}
		}
		time++;
	}
	//cout << "FFF" << endl;
	//copyMap(cmap, map);
	return time+1;

}
void dfs(int idx) {
	if (idx == pCnt) {
		
		// 시뮬레이션
		int rtn = simulate();
		MIN = MIN > rtn ? rtn : MIN;

		return;
	}

	dfs(idx + 1);
	stairState[idx] = true;
	dfs(idx + 1);
	stairState[idx] = false;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		MIN = 987654321;

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				// 사람 수 세기
				if (map[i][j] == 1) {
					pCnt++;
					cv.push_back({ i,j });
				}
				else if (map[i][j] >= 2) {
					stairs.push_back({ i,j, map[i][j] });
				}
			}
		}
		// 계단 조합 만들기
		dfs(0);

		cout << "#" << t << " " << MIN << "\n";

		//초기화
		memset(stairState, 0, sizeof(stairState));
		memset(sCnt, 0, sizeof(sCnt));
		cv.clear();
		stairs.clear();
		pCnt = 0;
	}
	return 0;
}