#include<iostream>
#include<vector>
using namespace std;
int N, dy[4] = { 0,-1,0,1 }, dx[4] = { 1,0,-1,0 };
//0,1,2,3, -> 우, 상, 좌, 하
bool visited[101][101], adj[101][101];
struct Node {
	int x, y, d, g;
};
Node curves[21];
vector<int> generation[21];
void setGeneration(int idx) {
	Node cur = curves[idx];

	// 0세대, 1세대 지정
	generation[idx].push_back(cur.d);
	generation[idx].push_back((cur.d + 1) % 4);

	// 2세대 ~ cur.g세대 지정
	for (int i = 2; i <= cur.g; i++) {
		// 이전세대 역순+1 % 4
		for (int j = generation[idx].size() - 1; j >= 0; j--) {
			generation[idx].push_back(((generation[idx][j] + 1) % 4));
		}
	}
	/*for (int i = 0; i< generation[idx].size(); i++) {
		cout << generation[idx][i] << " ";
	}
	cout << endl;*/
}
void move(int idx) {
	int y = curves[idx].y, x = curves[idx].x;
	//시작점 방문 표시
	visited[y][x] = true;

	for (int i = 0; i < generation[idx].size(); i++) {
		int d = generation[idx][i];
		int ny = y + dy[d];
		int nx = x + dx[d];

		visited[ny][nx] = true;
		y = ny;
		x = nx;
	}

}
int countRect() {
	int rtn = 0;
	
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) {
				rtn++;
			}
		}
	}
	return rtn;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;

	int x = 0, y = 0, d = 0, g = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >>d >> g;

		// make generation direction
		generation[i].push_back(d);
		for (int j = 0; j < g; j++) {
			for (int k = generation[i].size() - 1; k >= 0; k--) {
				generation[i].push_back((generation[i][k] + 1) % 4);
			}
		}

		//현재 visited체크
		visited[y][x] = true;
		for (int j = 0; j < generation[i].size(); j++) {
			y += dy[generation[i][j]];
			x += dx[generation[i][j]];
			visited[y][x] = true;
		}

		//setGeneration(i);
		//move(i);


	}

	cout<<countRect();

	return 0;
}

/*
실수한점
- 세로의 최대는 N이 아니라 100이여야 한다. 그래서 자꾸 map검사할때 continue먹음(몇분동안 뻘짓함)

01.08 해야할 것
- 각 선분이 이어져 있는 것 체크(단순히 점으로 하면 안이어져도 가능함)
- 선분에 따른 사각형 갯수 카운트

의문점
- 사각형을 계산할 때 4개의 점이 다 visited이더라도 선분이 안이어져있을 수 있는데 이건 어떻게 처리..
	-> 사각형 계산이 아니라 드래곤 커브에 통하는 점이면 가능이요

해결방법
- 너무 함수를 써서 헷갈렸다 - 코드를 리팩토링 해봐야 한다
- 무조건 실행부터 하지 말고 문제를 꼼꼼하게 읽고 ★설계★먼저 시작하기
- 함수를 안쓰고도 보기 쉬운 코드를 충분히 만들 수 있다
*/