#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int N = 0, arr[1001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int sum = 0, sum2=0;
	for (int i = 0; i < N; i++) {
		sum += arr[i];
		sum2 += sum;
	}
	cout << sum2;
	return 0;
}