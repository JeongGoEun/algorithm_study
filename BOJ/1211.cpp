#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int map[100][100], dy[3] = { -1,0,0 }, dx[3] = { 0,-1,1 },MIN=987654321,ans=0;
bool visited[100][100];
struct Node {
	int y, x, d;
};
void simulate(Node e) {
	int y = e.y, x = e.x, d = e.d,start=e.x;
	int cnt = 0;
	while (y < 99) {
		//���翡�� ����,������ Ȯ��
		y++;
		cnt++;
		if (x - 1 >= 0 && map[y][x - 1] == 1) {
			while (true) {
				if (x - 1 < 0 || map[y][x - 1] == 0)break;
				x--;
				cnt++;
			}
		}
		else if (x + 1 < 100 && map[y][x + 1] == 1) {
			while (true) {
				if (x + 1 >= 100 || map[y][x + 1] == 0)break;
				x++;
				cnt++;
			}
		}
	}
	if (MIN > cnt) {
		ans = start;
		MIN = cnt;
	}
	else if (MIN == cnt) {
		ans = ans < start ? start : ans;
	}
	return;
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	int N = 10;
	while (N--) {
		int t = 0;
		cin >> t;
		Node e;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 100; i++) {
			// ��� ������� ���Ͽ�
			if (map[0][i] == 1) {
				simulate({ 0,i,0 });
			}
		}
		cout << "#" << t << " " << ans << "\n";
		memset(visited, 0, sizeof(visited));
		ans = 0;
		MIN = 987654321;
	}
	return 0;
}

/*
������1
- ��� ��������� �˻��ؾ� �ϴϱ� �ڵ带 �����ؾ� ��
- cnt++�� ����, �¿�� ������ ������ϴϱ� x�� �������ִ� �κп����� �����ؾ���

������2
- ���x���� 99�� ���ͼ� �̻��ߴµ� �ּҰ� !����!�� ������..(MIN�� ������Ʈ line:34)
*/