#include<iostream>
#include<cstring>
using namespace std;
int T, N, ans = 0;
int dp[1000001];
bool nums[10];

void getAnswer() {
	int num = N,cnt=0;
	for (int i = N; i > 1; i--) {	//���� �� �ִ� �� �� ���� ū ��
		// �ش� �ڸ����� ������
		while (dp[i] > 0) {	//�� ���⸦ while�� ������� - if�� ��Ƶ� ���� �ʳ�
			if (num % i == 0) {
				cout << i << ", " << num << endl;
				cnt += 1 + dp[i];
				num /= i;
			}
			else
				break;
		}
		if (num == 1) {
			ans = cnt;
			return;
		}
	}
	ans = -1;
}

void makesNum(int num, int cnt) {
	if (cnt > 7) {
		// �ڸ����� 7�� ��
		return;
	}
	if (num > N) {
		return;
	}
	if (cnt > 0) {
		// �ش� �� �ڸ� �� ����
		dp[num] = cnt;
	}
	for (int i = 0; i < 10; i++) {
		if(nums[i])
			makesNum(10 * num + i, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 10; i++) {
			cin >> nums[i];
		}
		cin >> N;

		if (N == 1 && nums[1]) {
			ans = 2;
		}
		else {
			makesNum(0, 0);
			getAnswer();
		}
		cout << "#" << t << " " << ans << "\n";

		memset(dp, 0, sizeof(dp));

	}
	return 0;
}
/*
������1 - ������ �������� ����(N/10�� �ƴ϶� N%10�̿��� ��)
�� ����ó���� �ʹ� ����(����� �ϸ� �� 1�϶��� �ٷ� ���ڸ���+1�� �Ǿ�� �Ѵ�)
-> �˻���� �� �� �ִ� ���� �ִ�� ���������� ��� ��

Ǯ��
- �켱 ����Ž���� �̿��ؼ� �ִ� ���ڱ��� ���ϴ� ����� �˰ڴ�

*/