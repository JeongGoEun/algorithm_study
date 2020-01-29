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
	//!! 최대 사이즈 문자열의 사이즈로 맞춰서 계산
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
문제점1
- for문 + while문으로 범위를 넓혀가는 방법을 선택했는데 20개중 2개만 맞음,,

풀이법
- 해당 idx가 중점이라고 생각하고 각 최대길이를 구함

*/