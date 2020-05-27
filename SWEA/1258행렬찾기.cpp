#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Node {
	int y, x;
};
int T, N,map[101][101];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
bool visited[101][101];
vector<Node> ans;
Node bfs(int y, int x);
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}
bool comp(Node n1, Node n2) {
	int size1 = n1.y * n1.x;
	int size2 = n2.y * n2.x;
	if (size1 == size2) {
		return n1.y < n2.y;
	}
	return size1 < size2;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	string tmp;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > 0 && !visited[i][j]) {
					//cout << "start " << i << ", " << j << endl;
					Node n = bfs(i, j);
					ans.push_back(n);
				}
			}
		}
		sort(ans.begin(), ans.end(), comp);
		cout << "#" << t<<" "<<ans.size();
		for (int i = 0; i < ans.size(); i++) {
			cout <<" "<< ans[i].y << " " << ans[i].x;
		}
		cout << "\n";

		//초기화
		memset(visited, 0, sizeof(visited));
		ans.clear();
	}
	return 0;
}
Node bfs(int y, int x) {
	int yLen = 1, xLen = 0;
	
	// 가로 길이 확인
	for (int j = x; j < N; j++) {
		if (map[y][j] == 0)break;

		visited[y][j] = true;
		xLen++;
	}

	// 세로길이 확인
	for (int i = y+1; i < N; i++) {
		if (map[i][x] == 0)break;

		for (int j = 0; j < xLen; j++) {
			visited[i][x+j] = true;
		}
		yLen++;
	}
	
	/*cout << yLen << ", " << xLen << endl;
	print();*/
	return { yLen, xLen };
}