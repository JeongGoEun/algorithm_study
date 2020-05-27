#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int order[10], int mal[4], MAX = 0;
int score[35];
bool visited[35];   //�� �ִ��� Ȯ��


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

    //�� 4�� �̵�
    for (int i = 0; i < 4; i++) {
        int idx = mal[i], cnt=order[depth];
        int prev = idx;

        //�̵�
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
- �ִ밡 �Ǳ� ���ؼ� ���� �ִ��� ���� �������Ѿ� �Ѵ�.
=> ���� �� ���� �� �ʿ䰡 ����(�ּ� �Ÿ��� ���� ���� ���� �����״ϱ�)


*/