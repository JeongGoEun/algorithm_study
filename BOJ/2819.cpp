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
�ǹ���
- �湮 �ߺ� ����� �����ѵ� �̰� ��� ó������� ��? - visitedó�� ���ϸ� �ȴ�

������
- memset(map, 0, sizeof(map));���⿡�� map�� string������ �ٲ����ϱ� memset�� �ȸ����� ��Ÿ�ӿ����߻�
	�̰� �ذ��Ϸ��� ���? - memset�� 0�� �Ǳ� ������ �ϳ��ϳ� �ʱ�ȭ ����� �� �� -> for�� ������ �ʱ�ȭ �ϴϱ� ��

������
- ���� ���̾����� �ʹ� �����ϰ� ������ �����Ѵ�. �ٽ��� ���� ����� ����� �ҵ�
*/