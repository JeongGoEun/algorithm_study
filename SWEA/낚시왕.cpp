#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int  dy[5] = { 0,-1,1,0,0 }, dx[5] = { 0,0,0,1,-1 };
int R, C, M;
struct Shark {
	// y,x,속력,이동방향,크기,거리
	int y, x, s, d, z,idx;
};
vector<Shark> map[101][101];

//struct comp {
//	bool operator()(Shark s1, Shark s2) {
//
//		return s1.dist > s2.dist;
//	}
//};
//priority_queue<Shark, vector<Shark>, comp> sharks[101];
bool comp(Shark s1, Shark s2) {
	return s1.z > s2.z;
}

//함수들
void print();
int simulate();
void moveSharks();
int changeDir(int d);

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> R >> C >> M;
	int tmpIdx = 1;
	for (int i = 0; i < M; i++) {
		Shark s;
		cin >> s.y >> s.x >> s.s >> s.d>>s.z;
		//처음 거리는 y값-1
		s.idx = tmpIdx++;

		if (s.d <= 2) {
			// 상 하
			s.s = s.s % (2 * R - 2);
		}
		else {
			//좌 우
			s.s = s.s % (2 * C - 2);
		}

		//pq에 추가
		map[s.y][s.x].push_back(s);
	}
	//print();
	int ans = simulate();
	cout << ans;
	return 0;
}
int simulate() {
	int sum = 0;
	for (int j = 1; j <= C; j++) {
		// 현재 위치에서 가장 가까운 상어 잡음
		Shark cur;
		//cout << endl << j << endl;
		for (int i = 1; i <= R; i++) {
			if (!map[i][j].empty()) {
				cur = map[i][j][0];
				sum += cur.z;
				//cout << sum <<"<-"<<cur.z<< endl;

				map[i][j].clear();
				break;
			}
		}
		
		// 상어들 이동
		//cout << j << endl;
		moveSharks();
		//print();
	}

	return sum;
}
void moveSharks() {
	bool visited[10001] = { 0, };
	int ny = 0, nx = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// 상어가 있을 때
			if (!map[i][j].empty()) {
				// 무조건 하나 보장
				Shark cur = map[i][j][0];
				
				// 이미 옮겨진 애라면X
				if (visited[cur.idx])continue;

				// i,j에 추가된 애가 있을 수도 있어서 clear하면 안된다
				// 얘 빼고 다시 넣어야 함
				vector<Shark> tmp;
				if (map[i][j].size() > 1) {
					
					for (int k = 0; k < map[i][j].size(); k++) {
						if (visited[map[i][j][k].idx]) {
							tmp.push_back(map[i][j][k]);
						}
					}
				}
				map[i][j].clear();
				if (!tmp.empty()) {
					//복사본 넣어주기
					for (int k = 0; k < tmp.size(); k++) {
						map[i][j].push_back(tmp[k]);
					}
				}

				ny = cur.y;
				nx = cur.x;
				
				//cout << "charge\n";
				//cout << cur.y << ", " << cur.x <<", "<<cur.d<< endl;
				//d방향으로 이동 s만큼
				for (int k = 0; k < cur.s; k++) {
					cur.y += dy[cur.d];
					cur.x += dx[cur.d];
					if (cur.y < 1) {
						cur.y = 1;
						cur.d = changeDir(cur.d);
						k--;
					}
					else if (cur.y > R) {
						cur.y = R;
						cur.d = changeDir(cur.d);
						k--;
					}
					else if (cur.x < 1) {
						cur.x = 1;
						cur.d = changeDir(cur.d);
						k--;
					}
					else if (cur.x > C) {
						cur.x = C;
						cur.d = changeDir(cur.d);
						k--;
					}
					//cout << cur.y << ", " << cur.x << ", " << cur.d << endl;
				}
				//cout << cur.y << ", " << cur.x << ", " << cur.d << endl << endl;

				// 이동 한 곳에 넣기
				map[cur.y][cur.x].push_back(cur);

				//visited표시
				visited[cur.idx] = true;
			}
		}
	}

	// 이동 마치고 두개 이상 확인
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// 상어가 있을 때
			if (map[i][j].size()>=2) {
				//cout << "heavy" << endl;
				sort(map[i][j].begin(), map[i][j].end(), comp);

				// 가장 무거운거 남기고 없앰
				Shark maxShark = map[i][j][0];
				map[i][j].clear();
				map[i][j].push_back(maxShark);
			}
		}
	}
}
int changeDir(int d) {
	if (d <= 2) {
		return 3 - d;
	}
	else {
		return 7 - d;
	}
}
void print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!map[i][j].empty()) {
				Shark s = map[i][j][0];
				cout << s.y << ", " << s.x << " || " << s.s << " - " << s.z <<" - "<<s.d<< endl;
			}
		}
	}
}