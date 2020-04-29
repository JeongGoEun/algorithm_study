#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
int N, M, dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };

vector<vector<int>> K, L;
void turn(vector<vector<int>>& k) {
	vector<vector<int>> rtn(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rtn[j][N-i-1] = k[i][j];
		}
	}
	k = rtn;
}
void print(vector<vector<int>> p) {
	cout << endl;
	for (int i = 0; i < p.size(); i++) {
		for (int j = 0; j < p.size(); j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}
bool simulate(int y, int x, vector<vector<int>> padding) {
	bool rtn = true;
	vector<vector<int>> tmp(padding.size(), (vector<int>(padding.size())));
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			tmp[i][j] = K[i - y][j - x];
		}
	}

	// Lock Ȯ��
	for (int i = N - 1; i < N - 1 + M; i++) {
		for (int j = N - 1; j < N - 1 + M; j++) {
			if (tmp[i][j] + padding[i][j] != 1) {
				rtn = false; break;
			}
		}
		if (!rtn)break;
	}

	return rtn;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	N = key.size();
	M = lock.size();
	K = key;
	L = lock;
	// ��ó�� lockȮ��

	// padding ���� ���� ����
	int psize = M+2*(N-1);
	vector<vector<int>> padding(psize, vector<int>(psize));

	// ����� Lockä���ֱ�
	for (int i = N - 1; i <= psize - N; i++) {
		for (int j = N - 1; j <= psize - N; j++) {
			padding[i][j] = lock[i - N + 1][j - N + 1];
		}
	}

	// 0~360 ȸ���ϱ�
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i <= psize - N; i++) {
			for (int j = 0; j <= psize - N; j++) {
				if (simulate(i, j, padding)) {
					return true;
				}
			}
		}
		turn(K);
	}

	return false;
}

/*
����1
- ���� �ʴ� ������ ������ ��� �Ǵ���?
	- string���� ���� visitedó�� Ȯ���ϸ� ���� ������
	=> dfs�� �����ϴ� ������ �ƴ϶� padding�� �̿��� ��������.

����2
- ���׸����̼� ���� �߻�.. - N,M�� �Ųٷ� �Ἥ ����
- padding������ �� �� ����� ��Ȯ�� ���ϴ� ������ ����
���� [https://regularmember.tistory.com/186]
*/