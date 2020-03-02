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
����
- dfs�� 1���� S���� Ž�� -> �ð��ʰ�

Ǯ��
- ���� ũ����? => �յ��ϰ� �����ִ°� ����Ʈ
- �� ó�� �߰����� ���� ã�� �������� �յ��ϰ� �����ִ� ��
*/