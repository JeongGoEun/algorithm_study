#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N, M, T, x, d, k;
int map[51][51];
bool check;
struct Node {
	int y, x, val;
};
void print() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void turn(int h, int flag) {
	// �ð� or �ݽð� ȸ��
	int tmp = 0;

	if (!flag) {
		tmp = map[h][M];
		for (int i = M - 1; i >= 1; i--) {
			map[h][i + 1] = map[h][i];
		}
		map[h][1] = tmp;
	}
	else {
		tmp = map[h][1];
		for (int i = 1; i < M; i++) {
			map[h][i] = map[h][i + 1];
		}
		map[h][M] = tmp;
	}
}

// ���� �� �����
bool eraseAdj(Node n) {
	queue<Node> q;
	q.push(n);
	map[n.y][n.x] = 0;

	int left = 0, right = 0, up = 0, down = 0;
	bool flag = false;
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		//�翷 Ȯ��
		left = (cur.x == 1) ? M : cur.x - 1;
		right = (cur.x == M) ? 1 : cur.x + 1;

		if (map[cur.y][left] == cur.val) {
			q.push({ cur.y, left, cur.val });
			map[cur.y][left] = 0;
			flag = true;
		}
		if (map[cur.y][right] == cur.val) {
			q.push({ cur.y, right, cur.val });
			map[cur.y][right] = 0;
			flag = true;
		}

		//��, �Ʒ� Ȯ��
		if (cur.y == 1) {
			up = 2;
			if (map[up][cur.x] == cur.val) {
				q.push({ up, cur.x, cur.val });
				map[up][cur.x] = 0;
				flag = true;
			}
		}
		else if (cur.y == N) {
			up = N - 1;
			if (map[up][cur.x] == cur.val) {
				q.push({ up, cur.x, cur.val });
				map[up][cur.x] = 0;
				flag = true;
			}
		}
		else {
			up = cur.y + 1;
			down = cur.y - 1;

			if (map[up][cur.x] == cur.val) {
				q.push({ up, cur.x, cur.val });
				map[up][cur.x] = 0;
				flag = true;
			}
			if (map[down][cur.x] == cur.val) {
				q.push({ down, cur.x, cur.val });
				map[down][cur.x] = 0;
				flag = true;
			}
		}

	}
	// �׷��� ���� ����
	if (!flag) {
		//�ǵ����ֱ�
		map[n.y][n.x] = n.val;
	}
	return flag;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	while(T--){
		// x�� ��� ������ d�������� k�� ȸ��
		cin >> x >> d >> k;
		k %= M;	//�ݺ� ����
		//cout <<"##################"<< i << "##################" << endl;
		// ȸ��
		for (int j = x; j <= M; j += x) {
			for (int l = 0; l < k; l++) {
				turn(j, d);
			}
		}
		//print();
		//cout << "turn complete\n" << endl;
		int sum = 0, cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] != 0) {
					if (eraseAdj({ i, j, map[i][j] })) {
						check = true;
						//print();
					}
					else {
						cnt++;
						sum += map[i][j];
					}
				}
			}
		}
		// �׷��� ���� ���ٸ� - ��ճ��� +-1
		if (!check) {
			double avg = (double)sum / (double)cnt;
			//cout << "nonono" <<sum<<", "<<cnt<< endl;

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (map[i][j] != 0) {
						if (map[i][j] > avg) {
							map[i][j] -= 1;
						}
						else if (map[i][j] < avg) {
							map[i][j] += 1;
						}
					}
				}
			}
			//print();
		}
		check = false;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ans += map[i][j];
		}
	}
	cout << ans;
	return 0;
}
/*
����1
- ����� int������ �޾Ƽ� ��Ȯ���� ���ߴ�.
*/