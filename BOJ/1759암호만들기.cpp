#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int L, C;
char arr[15];
bool visited[15];
vector<char> v;
vector<string> ans;
set<string> st;
bool isVosel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	else {
		return false;
	}
}

void dfs(int idx, int cnt, int vcnt, int ccnt, string s) {
	if (cnt == L) {
		if (vcnt >= 1 && ccnt >= 2) {
			cout << s << "\n";
		}
		return;
	}
	if (idx == C)return;

	// 넣지 않거나, 넣을 때 (모음이거나, 자음일 때)
	if (isVosel(arr[idx])) {
		dfs(idx + 1, cnt + 1, vcnt + 1, ccnt, s + arr[idx]);
	}
	else {
		dfs(idx + 1, cnt + 1, vcnt, ccnt + 1, s + arr[idx]);
	}
	dfs(idx + 1, cnt, vcnt, ccnt, s);
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);
	dfs(0, 0, 0, 0, "");

	return 0;
}
/*
- dfs랑 백트래킹 문제랑 헷갈리지 않기

생각1
- 처음엔 문자를 L개로 조합하여 중복되지 않게 set에 저장한 다음 ans 벡터에 넣어주었더니 시간초과

풀이
- 해당 문자를 우선 정렬시킨다(->이전이라도 정렬하면 똑같으니까)
- 해당 문자를 넣거나, 넣지 않거나를 활용하여 순회한다.
*/