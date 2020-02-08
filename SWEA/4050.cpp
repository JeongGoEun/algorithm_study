#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T;
bool comp(int n1, int n2) {
	return n1 > n2;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		vector<int> v;
		int N = 0,sum=0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int n = 0;
			cin >> n;
			v.push_back(n);
			sum += n;
		}

		sort(v.begin(), v.end(), comp);

		int sub = 0;
		for (int i = 0; i < v.size()-2; i+=3) {
			sub += v[i + 2];
		}
		cout <<"#"<<t<<" "<< (sum - sub) << endl;

	}
	return 0;
}