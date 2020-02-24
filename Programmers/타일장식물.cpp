#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long dp[81];
long long solution(int N) {
    long long answer = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N + 1; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    answer = (dp[N] + dp[N + 1]) * 2;
    return answer;
}