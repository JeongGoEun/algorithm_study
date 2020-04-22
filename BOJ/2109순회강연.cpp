#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Node {
	int p, d;
};
int N;
vector<Node> v;
bool comp(Node n1, Node n2) {
	if (n1.d == n2.d) {
		return n1.p > n2.p;
	}
	return n1.d < n2.d;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		Node n;
		cin >> n.p >> n.d;
		v.push_back(n);
	}
	sort(v.begin(), v.end(), comp);
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i].p;
		pq.push(v[i].p);

		// pq -> 지금까지 한 강의의 수(pay가 높은 순으로 정렬)
		// 마감 기한일보다 지금까지 한 강의가 더 많으면 -> 가장 적은 페이가 빠짐
		if (v[i].d < pq.size()) {
			//cout << pq.top() << endl;
			sum -= pq.top();
			pq.pop();
		}
	}
	
	cout << sum << endl;
	return 0;
}
/*
생각1
- p,d구조체로 day와 p만큼 정렬 시키고 p가 큰 애들만 더하도록 함

풀이
- 하루에 하나씩 강의를 해서 이익을 얻는게 가장 좋음
- 일정 기한 안에만 처리하면 됨
- 우선순위 큐 사용
*/