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

		// pq -> ���ݱ��� �� ������ ��(pay�� ���� ������ ����)
		// ���� �����Ϻ��� ���ݱ��� �� ���ǰ� �� ������ -> ���� ���� ���̰� ����
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
����1
- p,d����ü�� day�� p��ŭ ���� ��Ű�� p�� ū �ֵ鸸 ���ϵ��� ��

Ǯ��
- �Ϸ翡 �ϳ��� ���Ǹ� �ؼ� ������ ��°� ���� ����
- ���� ���� �ȿ��� ó���ϸ� ��
- �켱���� ť ���
*/