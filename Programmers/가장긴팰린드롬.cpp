#include <iostream>
#include <string>
using namespace std;
int MAX = 0;
void evenCheck(int idx, string s) {
	int cnt = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (idx - i < 0 || idx + i >= s.size()) break;
		if (s[idx - i] == s[idx + i+1]) cnt += 2;
		else break;
	}
	MAX = MAX < cnt ? cnt : MAX;
	
	return;
}
void oddCheck(int idx, string s) {
	int cnt = 1;
	//!! �ִ� ������ ���ڿ��� ������� ���缭 ���
	for (int i = 1; i <= s.size(); i++) {
		if (idx - i < 0 || idx + i >= s.size()) break;
		if (s[idx - i] == s[idx + i]) cnt += 2;
		else break;
	}
	MAX = MAX < cnt ? cnt : MAX;
	return;
}
int solution(string s)
{
	int rtn = 0;

	for (int i = 0; i < s.size(); i++) {
		evenCheck(i, s);
		oddCheck(i, s);
	}
	return MAX;
}
/*
������1
- for�� + while������ ������ �������� ����� �����ߴµ� 20���� 2���� ����,,

Ǯ�̹�
- �ش� idx�� �����̶�� �����ϰ� �� �ִ���̸� ����

*/