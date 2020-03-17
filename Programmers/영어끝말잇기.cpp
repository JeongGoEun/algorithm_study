#include <string>
#include <vector>
#include <iostream>
#include<set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string> s;
	int cnt = 0;
	bool flag = true;
	s.insert(words[0]);
	for (int i = 1; i < words.size(); i++) {
		// 이미 있는 단어거나, 끝말잇기 성립이 안될 때
		if (s.count(words[i]) || (words[i - 1][words[i - 1].size() - 1] != words[i][0])) {
			cnt = i;
			flag = false;
			break;
		}
		s.insert(words[i]);
	}
	if (flag) {
		answer = { 0,0 };
	}
	else {
		/*if (cnt % n == 0) {
			answer.push_back(cnt / n);
			answer.push_back(n);
		}
		else {
			answer.push_back(cnt % n);
			answer.push_back(cnt / n + 1);
		}*/
		answer = { (cnt % n) + 1, (cnt / n) + 1 };
	}


	return answer;
}
/*
문제
1 - 놓친 부분이 있는 것 같음, 80/100
	풀이 => index를 구하는 부분에서 실수
*/