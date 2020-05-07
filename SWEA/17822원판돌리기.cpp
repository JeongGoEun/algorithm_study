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
	// 시계 or 반시계 회전
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

// 인접 수 지우기
bool eraseAdj(Node n) {
	queue<Node> q;
	q.push(n);
	map[n.y][n.x] = 0;

	int left = 0, right = 0, up = 0, down = 0;
	bool flag = false;
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();

		//양옆 확인
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

		//위, 아래 확인
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
	// 그러한 수가 없다
	if (!flag) {
		//되돌려주기
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
		// x의 배수 원판을 d방향으로 k번 회전
		cin >> x >> d >> k;
		k %= M;	//반복 방지
		//cout <<"##################"<< i << "##################" << endl;
		// 회전
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
		// 그러한 수가 없다면 - 평균내서 +-1
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
문제1
- 평균을 int형으로 받아서 명확하지 못했다.
*/