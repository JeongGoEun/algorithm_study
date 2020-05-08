#include<iostream>
#include<vector>
#include<set>
using namespace std;
int N, S, arr[20], ans;
bool visited[20];

void dfs(int idx, int sum) {
	// 지금까지의 부분수열 합계 + 현재가 0이라면
	//cout << sum << endl;
	if (idx == N) {
		// sum==s를 끝까지 비교하지 않고 부분수열이 끝까지 만들어졌다고 생각
		// -> cnt로 처음을 비교해 줄 필요가 없다
		if (sum == S) {
			ans++;
		}
		return;
	}


	//해당 원소를 선택 하거나, 하지 않거나
	dfs(idx + 1, sum + arr[idx]);
	dfs(idx + 1, sum);
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);

	// 공집할일 경우 S가 0이면 하나가 추가되기 때문에 예외 처리
	if (S == 0) {
		ans--;
	}
	cout << ans;
	return 0;
}
