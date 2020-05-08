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

	// ���� �ʰų�, ���� �� (�����̰ų�, ������ ��)
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
- dfs�� ��Ʈ��ŷ ������ �򰥸��� �ʱ�

����1
- ó���� ���ڸ� L���� �����Ͽ� �ߺ����� �ʰ� set�� ������ ���� ans ���Ϳ� �־��־����� �ð��ʰ�

Ǯ��
- �ش� ���ڸ� �켱 ���Ľ�Ų��(->�����̶� �����ϸ� �Ȱ����ϱ�)
- �ش� ���ڸ� �ְų�, ���� �ʰų��� Ȱ���Ͽ� ��ȸ�Ѵ�.
*/