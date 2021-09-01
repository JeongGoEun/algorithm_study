#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool visited[5];
char vowels[5] = {'A','E','I','O','U'};
int order, ans=1;

void dfs(int depth, string curStr, string ansStr) {
    // depth를 넘거나 ans를 찾았을 때
    if(depth > 5 || ans != 1) {
        return;
    }
    // 현재 값과 정답이 같을 때
    if(curStr == ansStr) {
        ans = order;
        return;
    }
    //cout<<depth<<", "<<order<<", "<<curStr<<endl;
    //A부터 시작
    order++;
    for(int i=0;i<5;i++) {
        visited[i]=true;
        dfs(depth+1, curStr+vowels[i], ansStr);
        visited[i]=false;
    }
    return;
}

int solution(string word) {
    if(word != "A") {
        dfs(0,"",word);
    }
    
    return ans;
}


