#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N, K, T, time;
int map[13][13], dy[5] = { 0, 0,0,-1,1 }, dx[5] = { 0, 1,-1,0,0 };
struct Node {
	int y, x, dir, idx;
};
vector<Node> v;
vector<int> vmap[13][13];	//인덱스만 저장하는 곳
void print() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!vmap[i][j].empty()) {
				cout << endl;
				for (int k = 0; k < vmap[i][j].size(); k++) {
					cout << vmap[i][j][k] + 1 << " ";
				}
			}
		}
	}

}
void move(int idx) {
	Node n = v[idx];
	vector<int> tmp;
	bool check = false;
	int ny = n.y + dy[n.dir], nx = n.x + dx[n.dir];
	if (ny<1 || nx<1 || ny>N || nx>N || map[ny][nx] == 2) {
		if (n.dir < 3) {
			n.dir = 3 - n.dir;
		}
		else {
			n.dir = 7 - n.dir;
		}
		// 새로 재설정 - 방향 반대로 하고 그 방향으로 한칸 이동
		v[idx].dir = n.dir;
		ny = n.y + dy[n.dir], nx = n.x + dx[n.dir];
		// 만약 같다면 아무것도 안함
		if (ny<1 || nx<1 || ny>N || nx>N || map[ny][nx] == 2) {
			return;
		}
	}

	for (int i = vmap[n.y][n.x].size() - 1; i >= 0; i--) {
		if (vmap[n.y][n.x][i] == idx) {
			tmp.push_back(vmap[n.y][n.x][i]);
			vmap[n.y][n.x].pop_back();
			break;
		}
		tmp.push_back(vmap[n.y][n.x][i]);
		vmap[n.y][n.x].pop_back();
	}

	//cout << ny << ", " << nx << ", " << map[ny][nx] << endl;


	if (map[ny][nx] == 0) {
		//cout <<endl<< "white" << endl;
		for (int i = tmp.size() - 1; i >= 0; i--) {
			int idx = tmp[i];
			v[idx].y = ny;
			v[idx].x = nx;
			vmap[ny][nx].push_back(idx);
		}
	}
	else if (map[ny][nx] == 1) {
		// << endl << "red" << endl;
		for (int i = 0; i < tmp.size(); i++) {
			int idx = tmp[i];
			v[idx].y = ny;
			v[idx].x = nx;
			vmap[ny][nx].push_back(idx);
		}
	}
}
void play() {
	bool flag = true;
	while (flag) {
		//1~K까지 순서대로 이동
		++time;
		for (int i = 0; i < K; i++) {
			move(i);
			//print();

			if (vmap[v[i].y][v[i].x].size() >= 4) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
		if (time >= 1000) {
			time = -1;
			break;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);	cin.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		Node n;
		cin >> n.y >> n.x >> n.dir;
		n.idx = i;
		v.push_back(n);
		vmap[n.y][n.x].push_back(i);
	}
	play();
	cout << time;

	return 0;
}
/*
문제1
- vector에 들어가는 순서가 헷갈려서 reverse해야 하는 부분이랑 그냥 넣어야 하는 부분을 반대로 했다
- 처음엔 다음 색깔을 보고 흰-빨-파 이렇게 처리했더리 파란색 처리하는 부분이 재귀적으로 반복해야 했음
- 그래서 파란색 처리하는 부분을 맨 처음으로 올리고 파-흰-빨-파 이렇게 했더니 히든 테케 안됨
- 파란색 처리하는 부분에서 파랑->파랑일 땐 그냥 return하게 했더니 됐음
*/