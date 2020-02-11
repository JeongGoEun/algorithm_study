#include<iostream>
#include<cmath>
using namespace std;
int N, R, C, r, c, ans, cnt;
bool flag = false;
void zFunc(int n, int y, int x) {
	if (y == r && x == c) {
		//여기서 바로 출력해주면 그 이후 값은 나타나지 않음
		cout << ans;
		return;
	}


	if (!(y <= r && r < y + n && x <= c && c < x + n)) {
		ans += n * n;
	}
	else {
		int mid = (n / 2);
		//cout << y << ", " << x << ", " << n << endl;

		//1, 2, 3, 4분면 다 검사
		zFunc(mid, y, x);
		zFunc(mid, y, x + mid);
		zFunc(mid, y + mid, x);
		zFunc(mid, y + mid, x + mid);
	}
}

int main() {
	cin >> N >> r >> c;
	R = C = (int)pow(2, N);
	zFunc(R, 0, 0);
	return 0;
}
/*
생각1
- 반으로 줄여가면서 재귀로 풀었더니 시간초과
- 사분면 순회 시 이 코드로 하면 임계값 설정이 어려워진다
		-어차피 네번씩 돌꺼니까 너무 어렵게 생각X
	for (int i = y; i < n; i+=mid) {
		for (int j = x; j < n; j+=mid) {
			중간 값 이후부터 시작
			cout << i << ", " << j << ", " << mid << endl;
			zFunc(mid, i, j);
		}
	}

풀이
- 범위를 계산해서 그 범위 안에 r,c가 없으면 그냥 전체 값을 더해주는 식으로
*/