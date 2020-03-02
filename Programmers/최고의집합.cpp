#include <string>
#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;
int N, S, MAX = -1;
vector<int> answer;

vector<int> solution(int n, int s) {
    int m = n / s,  r = n % s;
    if (m == 0) {
        answer = { -1 };
    }
    else {
        answer.reserve(m);
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            answer[i] = m;
            if (cnt < r) {
                answer[i] = m + 1;
                cnt++;
            }
        }
        sort(answer.begin(), answer.end());
    }
    return answer;
}
/*
문제
- dfs로 1부터 S까지 탐색 -> 시간초과

풀이
- 가장 크려면? => 균등하게 나눠주는게 포인트
- 맨 처음 중간값을 먼저 찾고 나머지를 균등하게 나눠주는 식
*/