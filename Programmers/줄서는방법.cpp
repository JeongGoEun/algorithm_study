#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long f = 1;

    for (int i = 1; i <= n; i++) {
        f *= i;
        v.push_back(i);
    }

    while (n > 0) {
        f = f / n;  //(n-1)!
        //나머지가 0이라면 -> 0번째 값, 아니면 -> k-1 / (n-1)!
        long long num = !k ? n - 1 : (k - 1) / f;
        answer.push_back(v[num]);   // 해당 값 넣기
        v.erase(v.begin() + num);   // 벡터에서 빼기
        k %= f; //나머지 수로 업데이트
        n--;
    }
    return answer;
}