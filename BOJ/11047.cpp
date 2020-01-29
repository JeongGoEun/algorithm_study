#include<iostream>
using namespace std;
int arr[11], N, K;
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = N-1; i >= 0; i--) {
		int n = arr[i];
		if (n <= K) {
			cnt += (K / n);
			K %= n;
			if (K == 0) break;
		}
	}
	cout << cnt;
	return 0;
}