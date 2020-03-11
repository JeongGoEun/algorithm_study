#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> people, int limit) {
    int cnt = 0, s = 0, e = people.size() - 1;
    sort(people.begin(), people.end());

    while (s < e) {
        if (people[s] + people[e] > limit) {
            //최소 + 최대 > limit -> 최대 값을 줄여줌
            cnt++;
            e--;
        }
        else {
            // 최소 + 최새 <= limit => 최소 늘리고 최대 줄이기
            cnt++;
            s++;
            e--;
        }
    }

    return cnt;
}
/*
생각
1 - 작은 순으로 sort -> limit이 찰 때까지 sum증가(sum이 0일때 보트의 수 증가) => 30/100

풀이
- 정렬하여 가장 (최소값+최대값 == limit)이 만족할 때까지 비교한다
->최소 인덱스, 최대 인덱스를 각각 정해서 구한다
*/