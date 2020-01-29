#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
int N, W[17][17],ans;
int dp[17][1 << 16];
//visited�� ��Ʈ����ũ�� ǥ���غ���
int tsp(int cur, int visited) {
	// !! �̹� �ּҰ� ���� �� �ִٸ�
	if (dp[cur][visited] != 0) {
		return dp[cur][visited];
	}

	//���� ��� ������ �湮�ߴٸ� => ex. 11111
	if (visited == (1 << N) - 1) {
		// ���翡�� 0������ �� �� �ִٸ�
		if (W[cur][0] != 0) {
			return W[cur][0];
		}
		return INF;
	}
	int ret = INF;
	for (int i = 0; i < N; i++) {
		// �̹� �湮�߰ų�, ���� ��ΰ� ���� ��
		if (visited & (1<<i) || W[cur][i] == 0) continue;

		// ��湮 �Ͽ� �ٽ� Ž��
		int result = tsp(i, (visited | 1 << i)) + W[cur][i];
		ret = min(ret, result);
	}
	// cur���� visited������ �ּҰ� �޸������̼�
	dp[cur][visited] = ret;
	
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	// visited�� 1�̶�°�, ex. 000000001=>�� ù��° �湮
	cout << tsp(0,1);
	return 0;
}

/*
����1
- ��� �׷����� �� ��ȸ�ϴ� dfs�� �����ߴ��� �ð��ʰ��� ����
- �׷��� ������ �ôµ� dp�� �ؾ��ϴ� �� ���Ҵ�.... dp������
- dfs����Ž������ �Ѵٸ� O(n^n)�̶� �ð��ʰ��� ���


Ǯ�̹�
- ��Ʈ����ũ�� �̿��� �޸������̼��� �����ؾ� �Ѵ�.
- dp�� �޸������̼��� �ϸ� �׻� �ּҰ��� �����Ǳ� ������ ���� ���� ����ϴ� ��

������ Ʋ���� �ƴ����� dp�� ��Ʈ����ŷ�� ����ؾ� �Ѵٴ� ���� ������

**��Ʈ����ũ**
visited | (1<<i) => i��°�� 1�߰�
visited & (1<<i) => i��°�� 1�ֳ� Ȯ��
(1<<N)-1 => N���� ��Ʈ�� ��� 1���� Ȯ��
*/