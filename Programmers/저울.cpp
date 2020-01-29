#include <algorithm>
#include <vector>
#include<iostream>

using namespace std;
int solution(vector<int> weight) {
	int answer = 0, sum = 0;
	sort(weight.begin(), weight.end());

	sum = weight[0];	//sum자체가 이전까지의 합

	for (int i = 1; i < weight.size(); i++) {
		// 이전까지의 합 + 1이 현재 무게보다 작을때(사이의 빈공간이 생김, 최소1은 갖고 있어야 함)
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
문제점1
- line 15에서 answer=sum+1로 했을땐 정답이 안됐다. 왜,,,,? 도대체..?
*/