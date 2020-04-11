#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;

int T, N, K;
int carr[6] = { 10,11,12,13,14,15 };	// A~F
string input;

struct Node {
	string str;
	int num;
};
bool comp(Node n1, Node n2) {
	return n1.num > n2.num;
}
vector<Node> v;
int convertStr(string num) {
	int cnt = 0,rtn=0,tmp=0;
	for (int i = num.size() - 1; i >= 0; i--) {
		double pNum = pow(16, cnt);
		if (num[i] >= '1' && num[i] <= '9') {
			tmp = num[i] - '0';
		}
		else {
			tmp = carr[num[i] - 'A'];
		}
		//cout << tmp << " * " << (int)pNum << endl;
		rtn += tmp * (int)pNum;
		cnt++;
	}
	return rtn;
}
int simulate() {
	// 3번 반복
	int MAX = 0, plus = input.size() / 4;
	set<string> s;
	
	for (int i = 0; i < plus; i++) {
		string copy = input;
		//cout << input << endl;

		for (int i = 0; i < input.size(); i+=plus) {
			string num = input.substr(i,plus);
			int cnum = convertStr(num);
			if (!s.count(num)) {
				//cout << num << ", " << cnum << endl;
				s.insert(num);
				v.push_back({ num, cnum });
			}
		}
		input = copy[copy.size() - 1] + copy.substr(0, copy.size() - 1);
	}
	sort(v.begin(), v.end(), comp);
	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i].str << ", " << v[i].num << endl;
	}*/
	return v[K-1].num;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K>>input;
		
		int ans = simulate();
		cout << "#" << t << " " << ans << "\n";
		
		//초기화
		v.clear();
	}
	return 0;
}
/*

1
24 16
044D3EBA6A647B2567A91D0E
*/