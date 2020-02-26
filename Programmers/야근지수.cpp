#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0, sum = 0;
    sort(works.begin(), works.end(), greater<int>());
    int idx = 0;
    while (true) {
        // 가장 큰 값을 찾아 그냥 -1 하면 됨
        works[idx]--;
        n--;
        if (n == 0) break;

        if (idx + 1 < works.size() && works[idx] < works[idx + 1]) {
            idx++;
        }
        else {
            idx = 0;
        }
    }
    for (int i = 0; i < works.size(); i++) {
        if (works[i] > 0)
            answer += (works[i] * works[i]);
    }
    return answer;
}

/*
생각1
- works를 내림차순으로 정렬하여 고르게 뺄 만큼 뺀다음, n을 다 쓸때까지 큰 수부터 1씩 빼주는 방식
- works가 2만이라 dfs하면 시간초과 나올것같음

=> 그냥 가장 큰 수부터 1만큼 고르게 빼주면 되는 문제
    - 앞부터 순서대로 최대값을 고민해주면 됨(4331->3331->2331->2231->2221->,,,)
*/