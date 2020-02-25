#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, cloc=0;
    sort(routes.begin(), routes.end());
    
    cloc = routes[0][1];    //첫 기준은 첫 차의 진출
    for (int i = 1; i < routes.size(); i++) {
        // i번째 진출이 현재의 진출보다 클 때 - 진출위치 변경
        if (routes[i][1] < cloc) {
            cloc = routes[i][1];
        }
        // i번째 진입 위치가 기준 진출위치보다 클 때
        if (routes[i][0] > cloc) {
            answer++;
            cloc = routes[i][1];
        }
    }

    return answer;
}

/*
그리디에서
- 최적을 찾아야 하니까 초기화는 무조건 제일 크거나 작은걸로 초기화
*/