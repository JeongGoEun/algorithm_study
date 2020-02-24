#include<iostream>
using namespace std;
int arr[3000][3000],N,result[3];
void func(int y, int x, int N) {
	int val = arr[y][x], cnt = 0;
	bool flag = true;
	for (int i = y; i < y+N; i++) {
		for (int j = x; j < x + N; j++) {
			if (val != arr[i][j]) {
				flag = false;
				break;
			}
			else {
				cnt++;
			}
		}
		if (!flag) break;
	}
	if (flag) {
		if (val == -1) {
			result[0]++;
		}
		else if (val == 0) {
			result[1]++;
		}
		else {
			result[2]++;
		}
	}
	else {
		int tmp = N / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				func(y + (tmp * i), x + (tmp * j), tmp);
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for(int j=0;j<N;j++)
			cin >> arr[i][j];
	}

	func(0, 0, N);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}
/*
!! 입출력 형식 잘보기
*/