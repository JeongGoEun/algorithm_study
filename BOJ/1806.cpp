#include<iostream>
using namespace std;
int N;
long long S, arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;

	// 부분합 구하기
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	long long sum=arr[1];
	int l = 1, r = 1, MIN = 100009;

	while (l <= r && r <= N) {
		if (sum < S) {
			r += 1;
			sum += arr[r];
		}
		else {
			MIN = r - l + 1 < MIN ? r - l + 1 : MIN;
			sum -= arr[l];	
			l += 1;
		}
	}
	// MIN값이 그대로라면 -> 불가능한 경우
	MIN = MIN == 100009 ? 0 : MIN;

	cout << MIN;
	return 0;
}

/*
문제점
- 부분합을 우선으로 구하고 i, j구간에 대하여 부분합을 구하는 이중for문을 돌렸더니 시간초과
- 문제 잘 읽기(S이상인데 S인 것으로 착각해서 틀림)

해결 방법 - 투포인터 방법을 써야한다. -> 투포인터 방법으로 구간합을 넓힌다.
- S값에 따라 결정되기 때문에 부분합을 구하고 나면 시간 오류
- 구간 합을 구하는 문제는 되도록이면 투포인터 방식을 생각하자.
*/