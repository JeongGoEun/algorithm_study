#include<iostream>
#include<queue>
#include<cstring>
#include<set>
#include<string>
using namespace std;

int T;
string map[4][4];
int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 }, ans;
set<string> s;
struct Node {
	int y, x;
	string str;
};
void dfs(Node cur, int depth) {
	if (depth==6) {
		if (!s.count(cur.str)) {
			ans++;
			s.insert(cur.str);
		}
		return;
	}
	//cout << cur.y << ", " << cur.x << ", " << cur.str << endl;
	for (int i = 0; i < 4; i++) {
		int ny = cur.y + dy[i];
		int nx = cur.x + dx[i];
		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4 ) {
			dfs({ ny, nx, cur.str + map[ny][nx] }, depth+1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dfs({ i, j, map[i][j] },0);
			}
		}
		cout << "#" << t << " " << ans << "\n";

		ans = 0;
		s.clear();
	}
	return 0;
}

/*
의문점
- 방문 중복 허용이 가능한데 이걸 어떻게 처리해줘야 함? - visited처리 안하면 된다

문제점
- memset(map, 0, sizeof(map));여기에서 map을 string형으로 바꿨으니까 memset이 안먹혀서 런타임에러발생
	이거 해결하려면 어떻게? - memset은 0만 되기 때문에 하나하나 초기화 해줘야 할 듯 -> for문 돌려서 초기화 하니까 됨

느낀점
- 쉬운 것이었지만 너무 복잡하게 문제를 생각한다. 핵심을 보는 방법을 배워야 할듯
*/