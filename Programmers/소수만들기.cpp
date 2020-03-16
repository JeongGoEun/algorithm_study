#include <vector>
#include <iostream>
using namespace std;
vector<int> v;
int answer = 0;
bool visited[5000], notPrime[5000];

void primeSet() {
    notPrime[0] = notPrime[1] = 1;
    for (int i = 2; i <= 5000; i++) {
        if (!notPrime[i]) {
            for (int j = i + i; j <= 5000; j += i) {
                notPrime[j] = true;
            }
        }
    }
}
void dfs(int idx, int cnt, int sum) {
    if (cnt == 3) {
        if (!notPrime[sum]) {
            answer++;
        }
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1, sum + v[i]);
            visited[i] = false;
        }
    }
}
int solution(vector<int> nums) {
    v = nums;
    primeSet();
    
    dfs(0, 0, 0);

    return answer;
}
/*
����
1 - dfs(����) + �����佺�׳׽��� ü -> 69.2/100
        => �ִ� ũ�⸦ 1000���� ��Ƽ� -> �ִ� 3000������ ��ƾ� �ߴ�(1000+1000+1000�� �ִ��̱� ����)

*/