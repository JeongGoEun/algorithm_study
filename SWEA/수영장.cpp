#include<iostream>
#include<cstring>
using namespace std;
int fee[4], use[13],MIN=987654321;	//1일, 1달, 3달, 1년
void dfs(int month, int sum) {
	if (month > 12) {
		MIN = MIN > sum ? sum : MIN;
		return;
	}

	int money = 0;
	//1일
	money = fee[0] * use[month];
	dfs(month + 1, sum + money);

	//1달
	money = fee[1];
	dfs(month + 1, sum + money);

	//3달
	money = fee[2];
	dfs(month + 3, sum + money);

	//1년
	money = fee[3];
	dfs(month + 12, sum + money);
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	int T = 0;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) {
			cin >> fee[i];
		}

		for (int i = 1; i <= 12; i++) {
			cin >> use[i];
		}
		//1월부터 시작
		dfs(1, 0);
		cout << "#" << t << " " << MIN << "\n";

		memset(fee, 0, sizeof(fee));
		memset(use, 0, sizeof(use));
		MIN = 987654321;
	}
	return 0;
}