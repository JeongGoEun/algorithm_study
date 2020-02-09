#include<iostream>
#include<string>
using namespace std;
int N,ans=987654321;
string s, tmp, res;
void push(int idx) {
	if (idx > 0) {
		tmp[idx - 1] = tmp[idx - 1] == '0' ? '1' : '0';
	}
	tmp[idx] = tmp[idx] == '0' ? '1' : '0';
	if (idx + 1 < N) {
		tmp[idx + 1] = tmp[idx + 1] == '0' ? '1' : '0';
	}
}
void dfs(int idx, int cnt) {
	if (idx == N-1) {
		// 스위치 안눌렀을 때
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (tmp[i] != res[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = ans > cnt ? cnt : ans;
		}

		// 마지막 스위치 누르고 다시 비교
		push(idx);
		cnt += 1;

		flag = true;
		for (int i = 0; i < N; i++) {
			if (tmp[i] != res[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			ans = ans > cnt ? cnt : ans;
		}
		return;
	}

	// 스위치 안누르고 비교
	if (tmp[idx - 1] == res[idx - 1]) {
		dfs(idx + 1, cnt);
	}

	// 스위치 누르고 다시 비교
	push(idx);
	if (tmp[idx - 1] == res[idx - 1]) {
		dfs(idx + 1, cnt+1);
	}
	
	//복구
	push(idx);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;

	cin >> s >> res;
	//0 안누를때
	tmp = s;
	dfs(1, 0);

	//0 누를 때
	tmp = s;
	push(0);
	dfs(1, 1);
	
	if (ans == 987654321) ans = -1;
	cout << ans;
	return 0;
}

/*
생각
1 - 처음부터 돌면서 다르면 N-1,N,N+1만큼 바꿔주면서 계산 => 시간초과
	(구할 수 없는 부분을 측정할 수 없다)

2 - 1번을 누를 때, 안누를 때를 for문을 이용한 함수 사용했지만 예외처리가 너무 많다
	(=>재귀로 구현해보자)

풀이
- 이전 까지 바꿀 수 있는건 현재를 누를 때이다.(현재에서 넘어가버리면 이전은 못간다)
- 현재에서 눌렀을 때, 안눌렀을 때의 이전값을 비교하며 누를지 안누를지 결정
*/