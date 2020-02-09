#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;
int dp[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    // dp[n]은 n을 거슬러주는 경우의 수
    // 0은 아예 안주는 경우 한가지가 있다.
    dp[0] = 1;

    for (int i : money) {
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }

    return dp[n];
}
/*
생각
1-단순 dfs로 해서 경우의 수를 count하도록 했더니 결과는 다 맞지만 효율성을 다 틀림

*/