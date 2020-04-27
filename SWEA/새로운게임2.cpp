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
vector<int> vmap[13][13];	//�ε����� �����ϴ� ��
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
		// ���� �缳�� - ���� �ݴ�� �ϰ� �� �������� ��ĭ �̵�
		v[idx].dir = n.dir;
		ny = n.y + dy[n.dir], nx = n.x + dx[n.dir];
		// ���� ���ٸ� �ƹ��͵� ����
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
		//1~K���� ������� �̵�
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
����1
- vector�� ���� ������ �򰥷��� reverse�ؾ� �ϴ� �κ��̶� �׳� �־�� �ϴ� �κ��� �ݴ�� �ߴ�
- ó���� ���� ������ ���� ��-��-�� �̷��� ó���ߴ��� �Ķ��� ó���ϴ� �κ��� ��������� �ݺ��ؾ� ����
- �׷��� �Ķ��� ó���ϴ� �κ��� �� ó������ �ø��� ��-��-��-�� �̷��� �ߴ��� ���� ���� �ȵ�
- �Ķ��� ó���ϴ� �κп��� �Ķ�->�Ķ��� �� �׳� return�ϰ� �ߴ��� ����
*/