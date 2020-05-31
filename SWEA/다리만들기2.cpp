#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int N, M, islandNum = 1;
int map[11][11], dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
int parent[7], minVal[7][7], MIN;
bool visited[11][11], adj[7][7];
struct Node {
	int y, x, num, cnt;
};
struct kruskalNode {
	int from, to, w;
};
vector<Node> v[7];
vector<kruskalNode> kv;
void print();
void numbering(int y, int x, int num);
bool check();
bool comp(kruskalNode n1, kruskalNode n2) {
	return n1.w < n2.w;
}

void unionFunc(int a, int b);
int find(int a);

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && map[i][j] != 0) {
				parent[islandNum] = islandNum;
				numbering(i, j, islandNum++);
			}
		}
	}
	/*print();
	cout << "---------------------------\n";*/
	//1�� ������ N������ bfs
	//for (int i = 1; i <=islandNum; i++)
	for (int i = 1; i < islandNum; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			//cout << v[i][j].y << ", " << v[i][j].x << " - " << v[i][j].num << endl;
			Node cur = v[i][j];
			for (int k = 0; k < 4; k++) {
				int ny = cur.y, nx = cur.x, cnt=0;
				while (true) {
					ny += dy[k];
					nx += dx[k];
					// visited ó��
					if (ny < 0 || nx < 0 || ny >= N || nx >= M)break;
					// �ڱ� �ڽ��� �ƴ϶��
					if (map[cur.y][cur.x] == map[ny][nx])break;

					cnt++;

					// 0�� �ƴϰ�, ���̰� 2�̻��̶��
					if (map[ny][nx] != 0) {
						cnt--;
						if (cnt < 2)break;
						//cout << cnt << endl;
						//cout << cur.y << ", " << cur.x << " ---  " << ny << ", " << nx << endl;
						kv.push_back({ map[cur.y][cur.x],map[ny][nx],cnt });
						break;
					}
				}
			}
		}
	}
	//cout << "finish" << endl;
	sort(kv.begin(), kv.end(), comp);

	for (int k = 1; k <= 2; k++) {
		for (int i = 0; i < kv.size(); i++) {
			int pf = find(kv[i].from);
			int pt = find(kv[i].to);
			if (pf != pt) {
				/*for (int i = 1; i < islandNum; i++) {
					cout << parent[i] << " ";
				}
				cout << endl;*/
				unionFunc(kv[i].from, kv[i].to);
				if (k == 1) {
					/*cout << kv[i].from << " -> " << kv[i].to  << endl;

					cout << pf << "-- " << pt << "--" << kv[i].w << endl;*/
					MIN += kv[i].w;
					/*for (int i = 1; i < islandNum; i++) {
						cout << parent[i] << " ";
					}
					cout << endl << endl;*/
				}
			}
		}
	}
	

	
	if (MIN == 0 || !check())MIN = -1;
	cout << MIN;
	return 0;
}
void print() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void numbering(int y, int x, int num) {
	queue<Node> q;
	q.push({ y,x,num });
	v[num].push_back({ y,x,num });
	map[y][x] = num;
	visited[y][x] = true;

	while (!q.empty()) {
		Node cur = q.front();	 q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i], nx = cur.x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (visited[ny][nx])continue;

			if (map[ny][nx] > 0) {
				visited[ny][nx] = true;
				map[ny][nx] = num;
				v[num].push_back({ ny,nx,num });
				q.push({ ny,nx,num });
			}
		}
	}
}
bool check() {
	for (int i = 1; i < islandNum - 1; i++) {
		if (find(i) != find(i + 1)) {
			return false;
		}
	}
	return true;
}
void unionFunc(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa != pb) {
		if (pa < pb) {
			// �̺κ��� parent[b]=pa���ϴ�  �ȵ� - �θ� �缳�� ����� ����
			//  �ڽĵ鵵 ������ �θ� ������� �Ǿ������ϱ�
			parent[pb] = pa;
		}
		else {
			parent[pa] = pb;
		}
	}
}
int find(int a) {
	if (a == parent[a]) {
		return a;
	}
	return parent[a] = find(parent[a]);
}
/*
����1
- cnt�� üũ�ϴ� ��
- union���� �ڽ��� �θ� �ƴ� �θ��� �θ� �ٲ��־�� ����(line.157)
- �� �Ǵ��� ����ó���� �ʿ���(union���� ������ �ٽ� ��� ������ ���ؼ� ��ü ����� �ݿ�)

=> ���ɸ� �� �¾Ҵٰ� ������� ���� �ݷʸ� ���ϴ�  ����� �˾ƾ߰ڴ�.
*/