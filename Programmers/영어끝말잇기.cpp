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
		// �̹� �ִ� �ܾ�ų�, �����ձ� ������ �ȵ� ��
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
����
1 - ��ģ �κ��� �ִ� �� ����, 80/100
	Ǯ�� => index�� ���ϴ� �κп��� �Ǽ�
*/