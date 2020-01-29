#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<int> v[100];
bool visited[100];
bool bfs() {
	queue <int> q;
	q.push(0);
	visited[0] = true;

	while (!q.empty()) {
		int n = q.front();
		q.pop();

		if (n == 99) {
			return true;
		}

		for (int i = 0; i < v[n].size(); i++) {
			int next = v[n][i];
			if (visited[next]) continue;
			
			q.push(next);
			visited[next] = true;
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N = 10,t=0,n=0;
	while (N--) {
		cin >> t >> n;
		for (int i = 0; i < n; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			v[n1].push_back(n2);
		}
		cout << "#" << t << " " << bfs() << "\n";
		for (int i = 0; i < 100; i++) {
			v[i].clear();
		}
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}

/*
- 딱히 어렵지 않은 문제
- 입력으로 주어진 배열보다 벡터로 처리하는게 쉬울것같아서 벡터로 처리
*/