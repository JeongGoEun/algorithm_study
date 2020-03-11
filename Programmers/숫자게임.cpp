#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    //내림차순 정렬
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    int idx = 0;
    for (int i = 0; i < A.size(); i++) {
        //cout<<A[i]<<", "<<*B.begin()<<endl;
        if (A[i] < B[idx]) {
            //더 크면
            answer++;
            //큰 선수 내보냄
            idx++;
        }
    }
    return answer;
}
/*
문제
- B를 정렬해서 lower_bound를 썼는데 2개정도 틀리고 효율성에서 틀렸다
    풀이 => 만약 그렇지 않다면 A에서 최대값과 비교를 해줘서 B팀이 이길 가능성이 커진다
- 더 크면 begin을 지우고, 아니면 가장 최소 end-1을 지우게 했더니 효율성은 안됐다
    (함수호출이 많아서 그런가보다)


풀이
- A팀의 순서는 고정하지 않아도 되나보다
- 그냥 앞에서 부터 비교하면 됨(굳이 벡터에서 지워줄 필요 없었다) => 똑같이 N번 반복이기 때문에

참고 출처 [https://sangdo913.tistory.com/140]
*/