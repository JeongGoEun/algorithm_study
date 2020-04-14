#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int blockSum,N,W,H,T,ans=987654321;
int map[15][12], cmap[15][12], dy[4] = { -1, 1,0,0 }, dx[4] = { 0, 0,-1,1 };
struct Node {
	int y, x, val;
};
void printMap() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << cmap[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int getBlockCnt() {
	int cnt=0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (cmap[i][j] != 0)cnt++;
		}
	}
	return cnt;
}
int breakBlock(int y, int x) {
	queue<Node> q;
	int rtn = 0;
	q.push({ y,x,cmap[y][x] });
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		rtn++;
		cmap[cur.y][cur.x] = 0;
		for (int k = 1; k < cur.val; k++) {
			for (int i = 0; i < 4; i++) {
				int ny = cur.y + (dy[i] * k);
				int nx = cur.x + (dx[i] * k);
				if (ny < 0 || nx < 0 || ny >= H || nx >= W)continue;
				if (cmap[ny][nx] != 0) {
					q.push({ ny,nx,cmap[ny][nx] });
				}
			}
		}
	}
	return rtn;
}
void moveMap() {
	for (int j = 0; j < W; j++) {
		for (int i = H-1; i >= 0; i--) {
			if (cmap[i][j] == 0) {
				int idx = i;
				while (i >= 0) {
					if (cmap[i][j] != 0)break;
					i--;
				}
				if (i >= 0) {
					cmap[idx][j] = cmap[i][j];
					cmap[i][j] = 0;
					i = idx;
				}
			}
		}
	}
}
void dfs(vector<int> v) {
	//cout << x << endl;
	if (ans == 0)return;
	if (v.size() == N) {
		// N�� �� á�� ��
		memcpy(cmap, map, sizeof(map));
		for (int i = 0; i < v.size(); i++) {
			int x = v[i];
			//cout << x << " ";
			for (int y = 0; y < H; y++) {
				if (cmap[y][x] != 0) {
					int bcnt = breakBlock(y, x);
					moveMap();
					break;
				}
			}
		}
		/*cout << endl;
		printMap();*/
		int cnt = getBlockCnt();
		if (cnt < ans) {
			ans = cnt;
		}
		return;
	}
	
	for (int i = 0; i < W; i++) {
		v.push_back(i);
		dfs(v);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0)blockSum++;
			}
		}
		for (int i = 0; i < W; i++) {
			vector<int> v;
			v.push_back(i);
			dfs(v);
		}
		

		cout << "#" << t << " " << ans << "\n";

		// �ʱ�ȭ
		ans = 987654321;
		memset(map, sizeof(map), 0);
	}
}

/*
����1
- ���� x=0�� ���� ó���ϰ� �������� x=0�ΰ��� ��Ƴ��� �ߴ�
	-> mapó���� �������
	=> ����� ����� ���� �� ���ϰ� map�� ������ cmap�� �̿��Ͽ� ������� ����
*/