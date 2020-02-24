#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

struct Node {
	int m, v;
};
multiset<int> s;
vector<Node> v;
int N, K;

bool comp(Node n1, Node n2) {
	return n1.v > n2.v;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> K;
	while (N--) {
		Node n;
		cin >> n.m >> n.v;
		v.push_back(n);
	}
	sort(v.begin(), v.end(), comp);

	while (K--) {
		int w = 0;
		cin >> w;
		s.insert(w);
	}

	multiset<int>::iterator it;
	long long sum = 0;

	// 벡터 순회 && 가방이 비어있지 않을 때 까지
	for (int i = 0; i < v.size() && !s.empty(); i++) {
		Node cur = v[i];
		bool flag = true;	//더 큰 애를 찾음
		it = s.lower_bound(cur.m);
		
		// ! 이런 예외사항 꼭 처리 - 처음에 런타임에러 발생
		if (it != s.end()) {
			// 해당 무게를 찾았으면
			sum += cur.v;
			s.erase(it);
		}
	}
	cout << sum;
	return 0;
}

/*
생각1
- 무게를 내림차순, 가방 무게를 오름차순으로 정렬하고 적절한 최대무게를 가진 가방을 고르면 된다.
	모든 방법을 다 탐색 =>최악의 경우 N^2 -> 90,000,000,000 시간초과 => 더 효율적인 방법을 찾아야 함

풀이
STL을 사용하여 더 효율적으로 탐색 - multiset!
multiset의 lower_bound를 쓰면 효율적(해당 무게보다 큰 무게가 처음 나온 부분이니까)
*/