#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int T, N,ans;
int map[16][16];
bool taste[16]; //1:A, 0:B
void printTaste() {
	cout << "A" << endl;
	for (int i = 0; i < N; i++) {
		if (taste[i] == 1) {
			cout<< i << " ";
		}
	}
	cout << endl << "B" << endl;
	for (int i = 0; i < N; i++) {
		if (taste[i] == 0) {
			cout << i << " ";
		}
	}
	cout << endl << endl;
}
void getSum() {
	int rtn = 0, asum=0,bsum=0;
	vector<int> va, vb;
	for (int i = 0; i < N; i++) {
		if (taste[i] == 1) {
			va.push_back(i);
		}
		else {
			vb.push_back(i);
		}
	}
	for (int i = 0; i < va.size(); i++) {
		for (int j = i + 1; j < va.size(); j++) {
			asum += (map[va[i]][va[j]] + map[va[j]][va[i]]);
		}
	}

	for (int i = 0; i < vb.size(); i++) {
		for (int j = i + 1; j < vb.size(); j++) {
			bsum += (map[vb[i]][vb[j]] + map[vb[j]][vb[i]]);
		}
	}
	//cout << asum << ", " << bsum << endl;
	int diff = abs(asum - bsum);
	ans = ans > diff ? diff : ans;
}
void dfs(int idx, int depth) {
	if (depth == N / 2) {
		//printTaste();
		getSum();
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!taste[i]) {
			taste[i] = true;
			dfs(i,depth + 1);
			taste[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 987654321;

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		dfs(0,0);
		cout << "#" << t << " " << ans << "\n";

		memset(taste, 0, sizeof(taste));
		memset(map, 0, sizeof(map));
	}
	return 0;
}
/*

1
4
0 5 3 8
4 0 4 1
2 5 0 3
7 2 3 0
*/