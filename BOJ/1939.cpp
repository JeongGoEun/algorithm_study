#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int N,M, MAX=-1, start,last;
bool visited[100001];
struct Node {
	int e, w;
};
vector<Node> adj[100001];
bool bfs(int weight) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == last) {
			return true;
		}

		for (int i = 0; i < adj[cur].size(); i++) {
			Node n = adj[cur][i];

			// 시작점 방문 확인, 다음 무게보다 작을 때(운반 가능)
			// 현재의 무게에만 집중 - mid로 필터됨
			if (!visited[n.e] && weight <= n.w) {
				q.push(n.e);
				visited[n.e] = true;
			}
		}

	}

	return false;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A=0, B=0, C=0;
		cin >> A >> B >> C;

		// 인접리스트 생성
		adj[A].push_back({ B,C });
		adj[B].push_back({ A,C });

		MAX = MAX < C ? C : MAX;	//최대값 갱신
	}
	cin >> start >> last;

	int s = 1, e = MAX, mid = 0;

	while (s <= e) {
		mid = (s + e) / 2;
		// 갈 수 있는지 -> 완전 탐색
		memset(visited, 0, sizeof(visited));
		if (bfs(mid)) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	cout << e;
	return 0;
}

/*
생각
- 무게로 줄이는건 이해하는데, 이분탐색으로 경로를 파악하는데 어려움이 있었다.
								=> 새로운 방법을 결합하는 것도 방법임

풀이
- 이분 탐색 + bfs문제(경로 탐색)였다.
무게에 따라 시작점에서 종점으로 갈 수 있는지 파악하는 문제

*/