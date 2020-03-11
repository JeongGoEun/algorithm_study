#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

// ����. ���, �������
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

	//(1,1)���� �����ϴ� ���� -> �ּ� ���簢�� ũ��� 2���� ����
	MAX = board[0][0];
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			//0�϶��� ���X
			int MIN = 987654321;    //dp�� �ϸ� ���� ��û Ŀ�� -> 2,90�̷� ���δ� ���� �ȵǴ°� ���� �ؾ� ��
			if (board[i][j] == 1) {
				// ����, ���, ��������� �ּҰ�
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
����1
- �׸���� ���� -> i,j���� size��ŭ ��ȸ�ϸ� üũ -> ȿ�������� 0��

Ǯ��
- dp�� �̿��ϴ� ��������.
- ���, ����, ������� �� -> ���� ���� ��+1 -> �ִ�� ��������� �簢���� ����
*/