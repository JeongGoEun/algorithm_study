#include<iostream>
#include<cstring>
using namespace std;
int T,N,room[205];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int in = 0, out = 0;
			cin >> in >> out;
			
			if (in % 2 == 1) {
				in += 1;
			}
			if (out % 2 == 1) {
				out += 1;
			}

			int tmp = 0;
			if (in > out) {
				tmp = in;
				in = out;
				out = tmp;
			}

			for (int j = in / 2; j <= out / 2; j++) {
				room[j]++;
			}
		}
		int cnt = 0;
		for (int i = 0; i < 200; i++) {
			cnt = cnt < room[i] ? room[i] : cnt;
		}
		cout << "#" << t << " " << cnt << "\n";

		memset(room, 0, sizeof(room));
	}
	return 0;
}
/*
생각1
- 일직선 상 각 범위를 주어서 그 사이에 존재한다면 cnt증가, 최대범위와 최소 범위 유지
							존재하지 않다면 최대범위, 최소범위 갱신 => 틀림

풀이
- 홀,짝 상관없다(같은 복도 공유) => 통일 해서 생각
- 누적 합 이용(겹치는 부분 중, 가장 많은 부분이 최소값이 된다)
- 방법이 1인 애들은 따로 들어갈 수 있으므로 카운트가 안들어감 => 가장 많이 겹치는게 최소가 됨

*/