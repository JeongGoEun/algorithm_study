#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

// 좌측. 상단, 좌측상단
int dy[3] = { 0,-1,-1 }, dx[3] = { -1,0,-1 };
void printf(vector<vector<int>> board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
int solution(vector<vector<int>> board)
{
	int N = board.size(), M = board[0].size(), MAX = 0;

	//(1,1)부터 시작하는 이유 -> 최소 정사각형 크기는 2부터 시작
	MAX = board[0][0];
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			//0일때는 고려X
			int MIN = 987654321;    //dp로 하면 값이 엄청 커진 -> 2,90이런 수로는 검증 안되는거 감안 해야 함
			if (board[i][j] == 1) {
				// 좌측, 상단, 좌측상단의 최소값
				for (int k = 0; k < 3; k++) {
					int ny = i + dy[k], nx = j + dx[k];
					if (MIN > board[ny][nx]) {
						MIN = board[ny][nx];
					}
				}
				//MIN = min(board[i - 1][j - 1], min(board[i][j - 1], board[i - 1][j]));
				board[i][j] = MIN + 1;
				if (MAX < board[i][j]) {
					MAX = board[i][j];
				}
			}
		}
		//printf(board);
	}

	return MAX * MAX;
}
/*
생각1
- 그리디로 접근 -> i,j에서 size만큼 순회하며 체크 -> 효율성에서 0점

풀이
- dp를 이용하는 문제였다.
- 상단, 좌측, 좌측상단 비교 -> 가장 작은 값+1 -> 최대로 만들어지는 사각형의 갯수
*/