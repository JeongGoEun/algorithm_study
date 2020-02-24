#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node {
	int from, to, w;
};
int parent[105];  //방문 섬 체크

struct comp {
	bool operator()(Node n1, Node n2) {
		return n1.w > n2.w;
	}
};
int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		return parent[a] = find(parent[a]);
	}
}
void unionF(int a, int b) {
	int pa = find(a), pb = find(b);
	if (pa != pb) {
		// !! 루트끼리 다르면 루트끼리 연결
		parent[pa] = pb;
	}
}
int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	priority_queue<Node, vector<Node>, comp> pq;
	for (int i = 0; i < costs.size(); i++) {
		Node n;
		n.from = costs[i][0];
		n.to = costs[i][1];
		n.w = costs[i][2];
		// 부모 init
		parent[n.from] = n.from;
		parent[n.to] = n.to;
		pq.push(n);
	}

	while (!pq.empty()) {
		Node cur = pq.top();
		pq.pop();
		//cout << cur.from << "-" << cur.to << "  " << cur.w << endl;
		int pf = find(cur.from), pt = find(cur.to);
		if (pf != pt) {
			answer += cur.w;
			unionF(cur.from, cur.to);
		}
	}
	return answer;
}

/*
풀이1
- 그래프적으로 최단거리를 구했는데 틀림
	=>(1,2,3) (4,5)이렇게 연결되어도 다 된걸로 파악 - 섬1과 2를 이어주는게 필요함
=>크루스칼 알고리즘 사용(union, find => 사이클 체크용, pq사용)

풀이2
=> 크루스칼 알고리즘 했는데 반만 맞았다..
- union과정에서 루트끼리 묶어주지 않고 자식이랑 루트끼리 묶어서 문제였음


*/