#include <string>
#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    long long mid=0, s=1, e=distance;
    while (s <= e) {
        int cnt = 0, prev = 0;
        mid = (s + e) / 2;
        //cout << s << ", " << e << " " << mid << endl;
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prev < mid) {
                // 중간값보다 작다면 해당 징검다리 부시기
                cnt++;
            }
            else {
                // 부서지지 않은 부분을 시작으로 진행해야 함
                prev = rocks[i];
            }
        }
        // 마지막 확인
        if (distance - prev < mid) {
            cnt++;
        }
        //cout << cnt << endl;
        if (cnt <= n) {
            // 최소값 중 가장 큰 값
            answer = answer < mid ? mid : answer;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return answer;
}