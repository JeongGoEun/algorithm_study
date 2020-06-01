#include<iostream>
using namespace std;
int N, M, H, MIN = 987654321;
int adj[50][50];
bool visited[50][50];

void dfs(int depth, int idx);
bool move(int w);
void print();

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M >> H;
	if (M == 0) {
		MIN = 0;
	}
	else {
		int a = 0, b = 0;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			//b와 b+1이 존재한다는 의미
			visited[a][b] = true;
		}

		//맨 처음에 검사
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (!move(i)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			MIN = 0;
		}
		else {
			dfs(0, 1);
		}
		if (MIN == 987654321)MIN = -1;
	}

	cout << MIN;
	return 0;
}
void dfs(int depth, int idx) {
	if (depth > 3) {
		return;
	}

	//print();
	//선 확인
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (!move(i)) {
			flag = false;
			break;
		}
	}
	if (flag) {
		MIN = MIN > depth ? depth : MIN;
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			//인접점들이 비어있다면
			if (!visited[i][j-1] && !visited[i][j] &&!visited[i][j+1]) {
				visited[i][j] = true;
				dfs(depth + 1, i);
				visited[i][j] = false;
			}
		}
	}
}
bool move(int w) {
	int j = w;
	for (int i = 1; i <= H; i++) {
		if (visited[i][j] == true) {
			// 오른쪽으로
			j++;
		}
		else if (visited[i][j-1] == true) {
			// 왼쪽으로
			j--;
		}
	}
	if (j == w)return true;
	return false;
}
void print() {
	cout << endl;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}
/*
생각1
- adj라는 2차원 배열에 1:출발점, 2:도착점으로 놓고 하나하나 사다리를 놓고 비교
	=> 시간초과, 가지치기가 중요했다

풀이
- a,b는 a에서 b와 b+1에 사다리가 놓여있다는 것 => b+1에 있으면 b+2는 자동으로 못놓음
	==> 일반화를 시키면 b-1,b,b+1에 아무것도 없어야 놓을 수 있다
	==> 각각 아무것도 없을 때 dfs를 타면 된다.
	==> move할 때, visited[i][j]를 보는 이유는 j와 j+1에 사다리가 있다고 가정했으니까
				   visited[i][j-1]을 보는 이유는 j-1이 있으면 j-2에서 시작된 거니까 왼쪽으로
*/