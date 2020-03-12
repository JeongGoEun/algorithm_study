#include <iostream>
#include <string>
#include <stack>
using namespace std;
stack<char> st;
int solution(string s)
{
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty()) {
            st.push(s[i]);
        }
        else {
            char c = st.top();
            if (c == s[i]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
    }

    if (st.empty()) {
        answer = 1;
    }
    else {
        answer = 0;
    }

    return answer;
}