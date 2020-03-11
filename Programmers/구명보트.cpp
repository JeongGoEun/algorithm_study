#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(vector<int> people, int limit) {
    int cnt = 0, s = 0, e = people.size() - 1;
    sort(people.begin(), people.end());

    while (s < e) {
        if (people[s] + people[e] > limit) {
            //�ּ� + �ִ� > limit -> �ִ� ���� �ٿ���
            cnt++;
            e--;
        }
        else {
            // �ּ� + �ֻ� <= limit => �ּ� �ø��� �ִ� ���̱�
            cnt++;
            s++;
            e--;
        }
    }

    return cnt;
}
/*
����
1 - ���� ������ sort -> limit�� �� ������ sum����(sum�� 0�϶� ��Ʈ�� �� ����) => 30/100

Ǯ��
- �����Ͽ� ���� (�ּҰ�+�ִ밪 == limit)�� ������ ������ ���Ѵ�
->�ּ� �ε���, �ִ� �ε����� ���� ���ؼ� ���Ѵ�
*/