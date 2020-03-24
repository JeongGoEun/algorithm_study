#include<iostream>
using namespace std;
int N, M, K,ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	// 여자2명 이상, 남자 1명 이상 , 남은사람>=제외할 사람 + 한 팀 이상
	while ((N>=2 && M>=1) && (N+M >= 3+K))
	{
		N -= 2;
		M -= 1;
		ans++;
	}
	cout << ans;
	return 0;
}
/*
생각1
- 남학생을 기준으로 n-2, m-1을 하면서 k보다 작아질 때 중단하는 방법

*/