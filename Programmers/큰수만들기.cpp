#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> v;
    int idx = 0;
    for (int i = 0; i < number.size(); i++) {
        // 맨 앞보다 커질 때 까지 비워줌
        while (!v.empty() && (v.back() < number[i]) && k > 0) {
            v.pop_back();
            k--;
        }
        // 더 큰 수 채움
        v.push_back(number[i]);
    }

    // 아직 다 안빼졌다면 - 같은 수가 여러번 있을 경우(ex. 10000)
    if (k > 0) {
        v.pop_back();
        k--;
    }
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    return answer;
}