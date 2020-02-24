#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int arr[101], T, N;
int visited[10001];
int solve() {
	vector<int> v;
	v.push_back(0);

	for (int i = 0; i < N; i++) {
		//	vec순환
		int len = v.size();
		//!! v.size()를 for문의 조건으로 걸었더니 무한루프**주의하기**
		for (int j = 0; j < len; j++) {
			// 벡터값과 합 구함 - 이전값은 고려하지 않음
			int n = v[j] + arr[i];
			
			if (!visited[n]) {
				//cout << n << endl;
				visited[n] = true;
				v.push_back(n);
			}
		}
	}

	return v.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		
		cout << "#"<<t<<" "<<solve() << "\n";

		memset(visited, 0, sizeof(visited));

	}
	return 0;
}

/*
문제점
- 순열과 조합으로 dfs를 만들려고 했는데 잘 안된다....
- 수가 무작정 커질 것 같아서 set을 하나 만들어서 처리하고자 했는데 안됨..->계속 중복 허용
- dfs할 때 idx랑 depth랑 조율하는게 어렵다
- dfs할때는 최대 100이기 때문에 O(2^100)이라 시간초과

해결법
- 2중 for문으로 가능한 문제였다
- 최대 점수는 100(최대 점수) * 100(최대 문제) => 10000점이라는걸 활용
- vector에 새로운 값을 추가하면서 flag를 거는 문제

쉬웠는데 어렵게 접근했다.. 부르트포스로 접근하는 방법좀 배워야겠다
*/