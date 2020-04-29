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

	// Lock 확인
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
	// 맨처음 lock확인

	// padding 가진 보드 생성
	int psize = M+2*(N-1);
	vector<vector<int>> padding(psize, vector<int>(psize));

	// 가운데에 Lock채워넣기
	for (int i = N - 1; i <= psize - N; i++) {
		for (int j = N - 1; j <= psize - N; j++) {
			padding[i][j] = lock[i - N + 1][j - N + 1];
		}
	}

	// 0~360 회전하기
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
문제1
- 되지 않는 마지막 조건은 어떻게 되는지?
	- string으로 만들어서 visited처럼 확인하면 되지 않을까
	=> dfs로 접근하는 문제가 아니라 padding을 이용한 문제였다.

문제2
- 세그멘테이션 문제 발생.. - N,M을 거꾸로 써서 문제
- padding문제할 때 각 사이즈를 정확히 구하는 연습을 하자
참고 [https://regularmember.tistory.com/186]
*/