#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node {
	int start, end;
};
bool comp(Node n1, Node n2) {
	if (n1.end == n2.end) {
		return n1.start < n2.start;
	}
	else {
		return n1.end < n2.end;
	}
}
int main() {
	vector<Node> v;
	int N=0,ans=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		Node n;
		cin >> n.start >> n.end;
		v.push_back(n);
	}
	sort(v.begin(), v.end(), comp);
	
	int end = v[0].end;
	ans = 1;

	for (int i = 1; i < v.size(); i++) {
		if (v[i].start == v[i].end) {
			ans++;
		} else if (v[i].start >= end) {
			end = v[i].end;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
/*
문제점
1- 시작 시간과 끝 시간이 같을 때 처리를 안해주었다 (line 31)
2- comp함수에서 end가 같을 때 처리를 안해주어서 틀림(line 9)
*/