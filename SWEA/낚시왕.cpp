#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int  dy[5] = { 0,-1,1,0,0 }, dx[5] = { 0,0,0,1,-1 };
int R, C, M;
struct Shark {
	// y,x,�ӷ�,�̵�����,ũ��,�Ÿ�
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

//�Լ���
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
		//ó�� �Ÿ��� y��-1
		s.idx = tmpIdx++;

		if (s.d <= 2) {
			// �� ��
			s.s = s.s % (2 * R - 2);
		}
		else {
			//�� ��
			s.s = s.s % (2 * C - 2);
		}

		//pq�� �߰�
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
		// ���� ��ġ���� ���� ����� ��� ����
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
		
		// ���� �̵�
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
			// �� ���� ��
			if (!map[i][j].empty()) {
				// ������ �ϳ� ����
				Shark cur = map[i][j][0];
				
				// �̹� �Ű��� �ֶ��X
				if (visited[cur.idx])continue;

				// i,j�� �߰��� �ְ� ���� ���� �־ clear�ϸ� �ȵȴ�
				// �� ���� �ٽ� �־�� ��
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
					//���纻 �־��ֱ�
					for (int k = 0; k < tmp.size(); k++) {
						map[i][j].push_back(tmp[k]);
					}
				}

				ny = cur.y;
				nx = cur.x;
				
				//cout << "charge\n";
				//cout << cur.y << ", " << cur.x <<", "<<cur.d<< endl;
				//d�������� �̵� s��ŭ
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

				// �̵� �� ���� �ֱ�
				map[cur.y][cur.x].push_back(cur);

				//visitedǥ��
				visited[cur.idx] = true;
			}
		}
	}

	// �̵� ��ġ�� �ΰ� �̻� Ȯ��
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// �� ���� ��
			if (map[i][j].size()>=2) {
				//cout << "heavy" << endl;
				sort(map[i][j].begin(), map[i][j].end(), comp);

				// ���� ���ſ�� ����� ����
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