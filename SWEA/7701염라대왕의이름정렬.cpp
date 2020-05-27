#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int T, N;
vector<string> v;
set<string> s;
bool comp(const string s1, const string s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	return s1.size() < s2.size();
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	string tmp;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		while (N--) {
			cin >> tmp;
			if (!s.count(tmp)) {
				s.insert(tmp);
				v.push_back(tmp);
			}
		}
		sort(v.begin(), v.end(), comp);
		cout << "#" << t << "\n";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << "\n";
		}

		v.clear();
		s.clear();
	}
}