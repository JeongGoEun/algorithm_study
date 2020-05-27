#include<iostream>
using namespace std;
struct Node {
	int y, x,dir;
};
Node head, tail;
int N, K, L;
int nextTurn[4][2], dirInfo[101][101], secondInfo[10001], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool existApple[101][101], isTurn[10001], visited[101][101];

int play();
void init();
void print();
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int h = 0, w = 0;
		cin >> h >> w;
		existApple[h][w] = true;
	}
	cin >> L;
	char c = 0;
	int time = 0;
	while(L--) {
		cin >> time >> c;
		if (c == 'L') {
			secondInfo[time] = 0;
		}
		else {
			secondInfo[time] = 1;
		}
		isTurn[time] = true;
	}
	
	head = { 1,1,3 };
	tail = { 1,1,3 };
	visited[1][1] = true;
	dirInfo[1][1] = 3;

	init();

	cout << play();
	return 0;
}
void init() {
	nextTurn[0][0] = 2;
	nextTurn[0][1] = 3;

	nextTurn[1][0] = 3;
	nextTurn[1][1] = 2;

	nextTurn[2][0] = 1;
	nextTurn[2][1] = 0;

	nextTurn[3][0] = 0;
	nextTurn[3][1] = 1;
}
int play() {
	int time = 0;
	while (true) {
		time++;

		//몸길이 늘리기
		int ny = head.y + dy[head.dir];
		int nx = head.x + dx[head.dir];
		int nd = head.dir;

		// 벽에 부딪히거나, 자기 자신의 몸이 있을 때
		if (ny<1 || nx<1 || ny>N || nx>N || visited[ny][nx]) {
			break;
		}

		// 머리 있는 곳 업데이트
		visited[ny][nx] = true;

		//방향을 바꿔야 되는 시간
		if (isTurn[time]) {
			//현재 방향에 따른 위치 바꿔주기
			nd = nextTurn[head.dir][secondInfo[time]];
			//cout << "change " << head.dir << " -> " << nd << endl;
		}

		//꼬리를 위한 방향 기록
		dirInfo[ny][nx] = nd;

		//머리 업데이트
		head = { ny,nx,nd };

		//사과가 있다면
		if (existApple[ny][nx]) {
			// 사과 먹음
			existApple[ny][nx] = false;
		}
		else {
			//몸 길이 줄이기
			visited[tail.y][tail.x] = false;
			
			int d = dirInfo[tail.y][tail.x];
			 
			tail.y += dy[d];
			tail.x += dx[d];
			tail.dir = d;
		}

		/*cout << endl<<time;
		print();*/
	}
	return time;
}
void print() {
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}