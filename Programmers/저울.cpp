#include <algorithm>
#include <vector>
#include<iostream>

using namespace std;
int solution(vector<int> weight) {
	int answer = 0, sum = 0;
	sort(weight.begin(), weight.end());

	sum = weight[0];	//sum��ü�� ���������� ��

	for (int i = 1; i < weight.size(); i++) {
		// ���������� �� + 1�� ���� ���Ժ��� ������(������ ������� ����, �ּ�1�� ���� �־�� ��)
		if (sum + 1 < weight[i]) {
			//answer = sum + 1;
			break;
		}
		else {
			sum += weight[i];
		}
	}
	answer = sum + 1;
	return answer;
}
/*
������1
- line 15���� answer=sum+1�� ������ ������ �ȵƴ�. ��,,,,? ����ü..?
*/