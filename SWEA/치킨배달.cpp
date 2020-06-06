#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct Node {
	int y, x, dist;
};
int N, M, MIN=987654321;
bool visited[15];
vector<Node> chicken, town;
int minDist[300];

void dfs(int idx, int cnt);
int getMinDist();

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = 0;
			cin >> tmp;
			if (tmp == 1) {
				//�մ�
				town.push_back({ i,j,100 });
			}
			else if (tmp == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	// ������ ġŲ�� ���� �����
	for (int i = 0; i < chicken.size(); i++) {
		visited[i] = true;
		dfs(i, 1);
		visited[i] = false;
	}

	cout << MIN;
	return 0;
}
void dfs(int idx, int cnt) {
	//�ִ� M��
	if (cnt > M) {
		return;
	}

	int tmp = getMinDist();
	//cout << cnt << ", " << MIN << ", " << tmp << endl;
	MIN = MIN > tmp ? tmp : MIN;

	for (int i = idx; i < chicken.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, cnt + 1);
			visited[i] = false;
		}
	}
}
int getMinDist() {
	int sum = 0;
	int dist = 0;
	bool flag = false;

	// �ּҰŸ� �ʱ�ȭ
	for (int i = 0; i < town.size(); i++) {
		minDist[i] = 987654321;
	}

	for (int i = 0; i < chicken.size(); i++) {
		//��� �� ġŲ���̶��
		if (!visited[i])continue;

		flag = true;
		for (int j = 0; j < town.size(); j++) {
			dist = abs(chicken[i].y - town[j].y) + abs(chicken[i].x - town[j].x);
			minDist[j] = minDist[j] > dist ? dist : minDist[j];
		}
	}
	if (!flag) {
		sum = 987654321;
	}
	else {
		for (int j = 0; j < town.size(); j++) {
			sum += minDist[j];
		}
	}
	return sum;
}