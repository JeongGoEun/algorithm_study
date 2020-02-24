#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<long long>  v;
	int K=0;
	long long N;
	cin >> K >> N;
	while (K--) {
		long long tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	long long s = 1, e = v[v.size() - 1], cnt=0, mid=0,ans=-1;
	while (s <= e) {
		cnt = 0;
		mid = (s + e) / 2;
		for (int i = 0; i < v.size(); i++) {
			cnt += (v[i] / mid);
		}

		if (cnt < N) {
			e = mid-1;
		}
		else {
			ans = mid;
			s = mid+1;
		}
	}
	cout << ans;
	return 0;
}