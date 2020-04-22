#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int operands[12], op[4], opCnt[4];
int T, N,MIN,MAX,opSum;
vector<int> opOrder;
int calc(int oper1, int oper2, int op) {
	int rtn = 0;
	if (op == 0) {
		rtn = oper1 + oper2;
	}
	else if (op == 1) {
		rtn = oper1 - oper2;
	}
	else if (op == 2) {
		rtn = oper1 * oper2;
	}
	else {
		rtn = oper1 / oper2;
	}
	return rtn;
}
void dfs(int cnt) {
	if (cnt == opSum) {
		int val = operands[0];
		for (int i = 0; i < opOrder.size(); i++) {
			cout << val << " ";
			val = calc(val, operands[i + 1], opOrder[i]);
		}
		cout << val << endl;
		MAX = MAX < val ? val : MAX;
		MIN = MIN > val ? val : MIN;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (opCnt[i] < op[i]) {
			opOrder.push_back(i);
			opCnt[i]++;
			dfs(cnt + 1);
			opOrder.pop_back();
			opCnt[i]--;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		MIN = INT32_MAX;
		MAX = INT32_MIN;
		cin >> N;
		for (int i = 0; i < 4; i++) {
			cin >> op[i];
			opSum += op[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> operands[i];
		}
		dfs(0);
		int ans = MAX - MIN;
		cout << "#" << t << " " << ans << "\n";

		memset(op, 0, sizeof(op));
		memset(opCnt, 0, sizeof(opCnt));
		memset(operands, 0, sizeof(operands));
		opOrder.clear();
		opSum = 0;
	}
	return 0;
}
/*
1
6
4 1 0 0
1 2 3 4 5 6
*/