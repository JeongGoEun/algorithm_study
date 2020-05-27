#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int order[10], int mal[4], MAX = 0;
int score[35];
bool visited[35];   //말 있는지 확인


void init();
int getNext(int idx);
void dfs(int depth, int sum);
int main() {
    ios::sync_with_stdio(0);    cin.tie(0);
    for (int i = 0; i < 10; i++) {
        cin >> order[i];
    }
    // score init
    init();

    dfs(0, 0);

    return 0;
}
void dfs(int depth) {
    if (depth == 10) {
        //
        return;
    }

    //말 4개 이동
    for (int i = 0; i < 4; i++) {
        int idx = mal[i], cnt=order[depth];
        int prev = idx;

        //이동
        while (cnt--) {
            idx = getNext(idx);
        }

        if (idx != 21 && visited[idx] == true) continue;
    }
}
void init() {
    for (int i = 0; i <= 20; i++) {
        score[i] = i*2;
    }
    score[21] = 22;   score[22] = 24; score[23] = 25; score[24] = 30; score[25] = 35;
    score[26] = 13; score[27] = 16; score[28] = 19;
    score[29] = 28; score[30] = 27; score[31] = 26;
}
int getNext(int idx) {
    if (idx == 5) {
        return 26;
    }
    else if (idx == 10) {
        return 21;
    }
    else if (idx == 15) {
        return 29;
    }
    else if (idx == 25) {
        return 20;
    }
    else if (idx == 28 || idx == 31) {
        return 23;
    }
    return idx + 1;
}
/*
- 최대가 되기 위해선 말을 최대한 많이 도착시켜야 한다.
=> 굳이 다 돌아 볼 필요가 없다(최소 거리를 가진 말이 가장 많을테니까)


*/