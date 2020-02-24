#include <string>
#include <vector>
#include<iostream>
using namespace std;
int MIN = 987654321, number, N;
// 곱해지는 수, 현재까지의 값, 곱해지는 수 카운트, 현재까지 카운트(최소)
void dfs(int num, int cnt) {
    if (cnt > 8) {
        return;
    }
    if (num == number) {
        MIN = MIN > cnt ? cnt : MIN;
        return;
    }

    //1~8까지 사칙연산
    int n = 0;
    for (int i = 0; i < 8; i++) {
        n = (10 * n) + N;
        dfs(num + n, cnt + i + 1);
        dfs(num - n, cnt + i + 1);
        if (n != 0) {
            dfs(num * n, cnt + i + 1);
            dfs(num / n, cnt + i + 1);
        }
    }
}
int solution(int _N, int _number) {
    N = _N;
    number = _number;

    dfs(0, 0);

    if (MIN == 987654321)MIN = -1;
    return MIN;
}