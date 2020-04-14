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
                // �߰������� �۴ٸ� �ش� ¡�˴ٸ� �νñ�
                cnt++;
            }
            else {
                // �μ����� ���� �κ��� �������� �����ؾ� ��
                prev = rocks[i];
            }
        }
        // ������ Ȯ��
        if (distance - prev < mid) {
            cnt++;
        }
        //cout << cnt << endl;
        if (cnt <= n) {
            // �ּҰ� �� ���� ū ��
            answer = answer < mid ? mid : answer;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return answer;
}