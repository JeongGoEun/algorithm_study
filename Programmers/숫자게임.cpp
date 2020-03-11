#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    //�������� ����
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    int idx = 0;
    for (int i = 0; i < A.size(); i++) {
        //cout<<A[i]<<", "<<*B.begin()<<endl;
        if (A[i] < B[idx]) {
            //�� ũ��
            answer++;
            //ū ���� ������
            idx++;
        }
    }
    return answer;
}
/*
����
- B�� �����ؼ� lower_bound�� ��µ� 2������ Ʋ���� ȿ�������� Ʋ�ȴ�
    Ǯ�� => ���� �׷��� �ʴٸ� A���� �ִ밪�� �񱳸� ���༭ B���� �̱� ���ɼ��� Ŀ����
- �� ũ�� begin�� �����, �ƴϸ� ���� �ּ� end-1�� ����� �ߴ��� ȿ������ �ȵƴ�
    (�Լ�ȣ���� ���Ƽ� �׷�������)


Ǯ��
- A���� ������ �������� �ʾƵ� �ǳ�����
- �׳� �տ��� ���� ���ϸ� ��(���� ���Ϳ��� ������ �ʿ� ������) => �Ȱ��� N�� �ݺ��̱� ������

���� ��ó [https://sangdo913.tistory.com/140]
*/