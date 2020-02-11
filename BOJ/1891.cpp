#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int N;
long long x, y;
string str;
struct Node {
	long long y, x;
};
Node s, e;

void findStr(long long n, long long y, long long x, string curStr) {
	if (curStr == str) {
		//cout << y << ", " << x << endl;
		s.y = y;
		s.x = x;
		return;
	}

	//1,2,3,4탐색
	long long mid = n / 2;
	int idx = curStr.size();

	if (str[idx] == '1') {
		findStr(mid, y, x + mid, curStr + "1");
	}
	else if (str[idx] == '2') {
		findStr(mid, y, x, curStr + "2");
	}
	else if (str[idx] == '3') {
		findStr(mid, y + mid, x, curStr + "3");
	}
	else {
		findStr(mid, y + mid, x + mid, curStr + "4");
	}
}

void findDst(long long n, long long y, long long x, string curStr) {
	//cout << curStr << endl;
	if (y == e.y && x == e.x) {
		cout << curStr;
		return;
	}

	// 범위에 없다면 볼 필요 없음
	if (!(y <= e.y && e.y < y + n && x <= e.x && e.x < x + n)) {
		return;
	}
	else {
		//1,2,3,4탐색
		long long mid = n / 2;
		findDst(mid, y, x + mid, curStr + "1");
		findDst(mid, y, x, curStr + "2");
		findDst(mid, y + mid, x, curStr + "3");
		findDst(mid, y + mid, x + mid, curStr + "4");
	}
}

int main() {
	cin >> N >> str >> x >> y;
	long long n = (int)pow(2, N);

	// 해당 좌표 찾기
	findStr(n, 0, 0, "");

	// 목적지 좌표 계산
	e.y = s.y + ((-1)*y);
	e.x = s.x + x;
	//cout << e.y << ", " << e.x << endl;
	if (e.y < 0 || e.x < 0 || e.y >= n || e.x >= n) {
		cout << -1;
	}
	else {
		findDst(n, 0, 0, "");
	}
	return 0;
}