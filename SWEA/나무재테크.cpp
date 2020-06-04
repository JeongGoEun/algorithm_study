#include<iostream>
#include<queue>
using namespace std;
struct Tree {
	int y, x, age;
};
int dy[8] = { -1,-1,-1,0,0,1,1,1 }, dx[8] = { -1,0,1,-1,1,-1,0,1 };
int N, M, K, A[10][10], added[10][10];
deque<Tree> dq[10][10];
void springAndSummer();
void fallAndWinter();
void printA();
int getTreeCnt();
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> added[i][j];
			A[i][j]=5;
		}
	}
	while (M--) {
		Tree t;
		cin >> t.y >> t.x >> t.age;
		t.y -= 1;
		t.x -= 1;
		dq[t.y][t.x].push_back(t);
	}
	while (K--) {
		springAndSummer();
		fallAndWinter();
	}

	cout << getTreeCnt();
	return 0;
}
void springAndSummer() {
	queue<Tree> deathTree;

	//�� - �ڽ��� ���̸�ŭ ����� �԰� ���� 1����
	deque<Tree> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dq[i][j].empty()) continue;

			q = dq[i][j];
			dq[i][j].clear();

			while (!q.empty()) {
				Tree cur = q.front();
				if (A[i][j] >= cur.age) {
					q.pop_front();

					//�ڽ��� ���̸�ŭ ��� �Ա�
					A[i][j] -= cur.age;
					cur.age += 1;
					//cout << "grow " << cur.y << ", " << cur.x << ", " << cur.age << endl;

					dq[i][j].push_back(cur);
				}
				else {
					break;
				}
			}
			//������ �����ֵ� ���ó��
			while (!q.empty()) {
				Tree cur = q.front();
				q.pop_front();
				//cout << "death " << cur.y << ", " << cur.x << ", " << cur.age << endl;
				A[cur.y][cur.x] += cur.age / 2;
			}
		}
	}
}
void fallAndWinter() {
	//���� ����
	deque<Tree> q;
	int ny = 0, nx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// ���� ���� �ʴ� �ֵ��� �ٷ� ó���ϵ��� �غ���
			A[i][j] += added[i][j];

			q = dq[i][j];
			int size = q.size();
			if (size == 0)continue;

			while (size--) {
				Tree cur = q.front();
				q.pop_front();
				if (cur.age % 5 == 0) {
					for (int i = 0; i < 8; i++) {
						ny = cur.y + dy[i];
						nx = cur.x + dx[i];
						//cout << ny << ", " << nx << endl;
						if (ny < 0 || nx < 0 || ny >= N || nx >= N)continue;
						// ���� ����� �ְ� ������ ������ ����
						//cout << "new tree " << ny << ", " << nx << endl;
						dq[ny][nx].push_front({ ny,nx,1 });
					}
				}
			}
		}
	}
	//cout << "winter\n";
	//printA();
}
int getTreeCnt() {
	int rtn = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rtn += dq[i][j].size();
		}
	}
	return rtn;
}
void printA() {
	cout << endl << "print A" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}