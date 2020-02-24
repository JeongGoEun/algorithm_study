#include<iostream>
using namespace std;
int n, p[100001], in[100001], inIdx[100001];
void traversal(int is, int ie, int ps, int pe) {
	if (is > ie || ps > pe) return;

	int root = p[pe];
	cout << root << " ";
	int rootIdx = inIdx[root];
	int left = rootIdx - is - 1;

	traversal(is, rootIdx - 1, ps, ps + left);
	traversal(rootIdx + 1, ie, ps + left + 1, pe - 1);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> in[i];
		inIdx[in[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	traversal(1, n, 1, n);
	return 0;
}