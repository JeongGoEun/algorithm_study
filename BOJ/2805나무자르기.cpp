#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<long long>  v;
	int N = 0;
	long long M;
	cin >> N >> M;
	while (N--) {
		long long tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	long long s = 0, e = v[v.size() - 1], sum = 0, mid = 0, ans = 0;
	while (s <= e) {
		sum = 0;
		mid = (s + e) / 2;
		for (int i = 0; i < v.size(); i++) {
			if(v[i]>mid)
				sum += (v[i] - mid);
		}

		if (sum < M) {
			e = mid - 1;
		}
		else {
			ans = ans < mid? mid : ans;
			s = mid + 1;
		}
	}
	cout << ans;
	return 0;
}