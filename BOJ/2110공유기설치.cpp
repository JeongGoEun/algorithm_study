#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,C,MAX=0;
vector<int> home;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int n = 0;
		cin >> n;
		home.push_back(n);
	}

	sort(home.begin(), home.end());
	int s = 1, e = home[home.size() - 1] - home[0], mid = 0;

	while (s <= e) {
		mid = (s + e) / 2;
		int cnt = 1, start = home[0];

		for (int i = 1; i < home.size(); i++) {
			int d = home[i] - start;	//기준까지의 거리

			if (d >= mid) {
				// 거리가 크거나 같을 때 -> 설치 가능
				cnt++;
				start = home[i];
			}
		}

		if (cnt < C) {
			e = mid - 1;
		}
		else {
			MAX = mid;
			s = mid + 1;
		}
	}
	
	cout << MAX;
	return 0;
}
/*
생각
- sort하고 각 인덱스를 저장해서 인덱스 차이가 더 작고, 거리가 큰 애들을 저장
=> 나올 수가 없음(4일때 L이 4라면 8을 갈 수 있어서 거리가 더 큼 근데 인덱스는 큼 -> 모순)

해결법
범위가 커질수록 설치할 수 있는 공유기의 갯수가 작아지는건 자명
즉, 최대한 왼쪽에 설치할수록, 다음 공유기는 더 왼쪽에 더 많이 설치 가능
*/