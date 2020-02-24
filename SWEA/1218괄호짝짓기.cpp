#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	for (int t = 1; t <= 10; t++) {
		int n = 0;
		string s = "";
		cin >> n>>s;
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '<') {
				st.push(s[i]);
			}
			else {
				if (st.empty()) break;

				if (s[i] == ')' && st.top() == '(') {
					st.pop();
				}else if (s[i] == ']' && st.top() == '[') {
					st.pop();
				}
				else if (s[i] == '}' && st.top() == '{') {
					st.pop();
				}
				else if (s[i] == '>' && st.top() == '<') {
					st.pop();
				}
				else {
					break;
				}
			}
		}
		bool ans = st.size() == 0 ? true : false;
		cout << "#" << t << " " << ans << "\n";
	}
	return 0;
}