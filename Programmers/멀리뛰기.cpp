#include<iostream>
long long MOD = 1234567, ans = 0, dp[2001];
using namespace std;

long long solution(int n) {

    dp[1] = 1;
    if (n == 1) return 1;

    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    return dp[n] % MOD;
}

/*
문제점
1- dfs, bfs로 돌렸더니 시간초과
2- dp 넣어줄 때 MOD까지 해서 넣어주기

풀이
5까지 구하면
1,2,3,5,8,... => 피보나치 수열이란 것을 알 수 있다.
dp로 해결
무조건 7이하까지는 구하고 해결해보기
*/