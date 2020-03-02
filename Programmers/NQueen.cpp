#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N, ans;
int map[13];
void printf() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
bool isPossible(int y, int x) {
    //0~y까지
    for (int i = 0; i < y; i++) {
        // 이전까지의 x값이 같거나(같은 행)
        // 대각선에 있다면(x좌표 차이 == y좌표 차이)
        if (map[i] == x || (abs(i-y) == abs(map[i]-x))) return false;
    }
    return true;
 }
void nq(int y) {
    if (y >= N) {
        ans++;
        return;
    }
    //printf();
    //cout << endl;
    for (int i = 0; i < N; i++) {
        
        if (isPossible(y,i)) {
            map[y] = i;
            nq(y + 1);
            map[y] = -1;
        }
    }
}
int solution(int n) {
    N = n;
    for (int i = 0; i < n; i++) {
        map[i] = -1;
    }
    nq(0);
    return ans;
}
/*
문제
- 지금의 행 다음으로 갈 수 있다면 (visit하지 않았다면) 이동하게 해서 끝까지 갔다면 ans++
- 다음에 갈 수 있는 경우의 수가 적어지기 때문에 이전을 기준으로 봐야 맞는듯

풀이
- 이전까지의 행을 비교하면서 퀸들을 위치해줌
- 이전 행의 x값과 지금의 행 y값을 비교해줌
*/