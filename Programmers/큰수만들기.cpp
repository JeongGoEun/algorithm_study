#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> v;
    int idx = 0;
    for (int i = 0; i < number.size(); i++) {
        // �� �պ��� Ŀ�� �� ���� �����
        while (!v.empty() && (v.back() < number[i]) && k > 0) {
            v.pop_back();
            k--;
        }
        // �� ū �� ä��
        v.push_back(number[i]);
    }

    // ���� �� �Ȼ����ٸ� - ���� ���� ������ ���� ���(ex. 10000)
    if (k > 0) {
        v.pop_back();
        k--;
    }
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
    }
    return answer;
}