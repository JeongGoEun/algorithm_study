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
    //0~y����
    for (int i = 0; i < y; i++) {
        // ���������� x���� ���ų�(���� ��)
        // �밢���� �ִٸ�(x��ǥ ���� == y��ǥ ����)
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
����
- ������ �� �������� �� �� �ִٸ� (visit���� �ʾҴٸ�) �̵��ϰ� �ؼ� ������ ���ٸ� ans++
- ������ �� �� �ִ� ����� ���� �������� ������ ������ �������� ���� �´µ�

Ǯ��
- ���������� ���� ���ϸ鼭 ������ ��ġ����
- ���� ���� x���� ������ �� y���� ������
*/