#include<iostream>
#include<string>
#include<stack>
using namespace std;
int N = 0, ans = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s = "";
		cin >> s;
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (st.empty()) {
				st.push(s[i]);
			}
			else {
				char cur = st.top();
				if (cur == s[i] && !st.empty()) {
					st.pop();
				}
				else {
					st.push(s[i]);
				}
			}
		}

		if (st.empty()) ans++;
	}
	cout << ans;
	return 0;
}
/*
생각
- 가운데 인덱스를 기점으로 양쪽으로 퍼져가면서 비교 (다르면->그 이전,이후값이 같아야함) 근데 틀림

풀이
- stack이용( - 괄호 짝 맞추기랑 비슷한 문제였다)
*/