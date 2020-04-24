#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    if (n == 1) {
        return answer;
    }
    answer.push_back(0);
    answer.push_back(1);
    if (n == 2) {
        return answer;
    }
    vector<int> tmp;

    for (int i = 3; i <= n; i++) {
        tmp.clear();
        for (int j = 0; j < answer.size(); j++) {
            tmp.push_back(answer[j]);
        }
        cout << endl;
        if (answer[answer.size() - 1] == 0) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }

        for (int j = tmp.size() - 1; j >= 0; j--) {
            answer.push_back(1 - tmp[j]);
        }
    }

    return answer;
}