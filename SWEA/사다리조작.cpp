#include<iostream>
using namespace std;
int N, M, H, MIN = 987654321;
int adj[50][50];
bool visited[50][50];

void dfs(int depth, int idx);
bool move(int w);
void print();

int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> M >> H;
	if (M == 0) {
		MIN = 0;
	}
	else {
		int a = 0, b = 0;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			//b�� b+1�� �����Ѵٴ� �ǹ�
			visited[a][b] = true;
		}

		//�� ó���� �˻�
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (!move(i)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			MIN = 0;
		}
		else {
			dfs(0, 1);
		}
		if (MIN == 987654321)MIN = -1;
	}

	cout << MIN;
	return 0;
}
void dfs(int depth, int idx) {
	if (depth > 3) {
		return;
	}

	//print();
	//�� Ȯ��
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (!move(i)) {
			flag = false;
			break;
		}
	}
	if (flag) {
		MIN = MIN > depth ? depth : MIN;
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			//���������� ����ִٸ�
			if (!visited[i][j-1] && !visited[i][j] &&!visited[i][j+1]) {
				visited[i][j] = true;
				dfs(depth + 1, i);
				visited[i][j] = false;
			}
		}
	}
}
bool move(int w) {
	int j = w;
	for (int i = 1; i <= H; i++) {
		if (visited[i][j] == true) {
			// ����������
			j++;
		}
		else if (visited[i][j-1] == true) {
			// ��������
			j--;
		}
	}
	if (j == w)return true;
	return false;
}
void print() {
	cout << endl;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}
/*
����1
- adj��� 2���� �迭�� 1:�����, 2:���������� ���� �ϳ��ϳ� ��ٸ��� ���� ��
	=> �ð��ʰ�, ����ġ�Ⱑ �߿��ߴ�

Ǯ��
- a,b�� a���� b�� b+1�� ��ٸ��� �����ִٴ� �� => b+1�� ������ b+2�� �ڵ����� ������
	==> �Ϲ�ȭ�� ��Ű�� b-1,b,b+1�� �ƹ��͵� ����� ���� �� �ִ�
	==> ���� �ƹ��͵� ���� �� dfs�� Ÿ�� �ȴ�.
	==> move�� ��, visited[i][j]�� ���� ������ j�� j+1�� ��ٸ��� �ִٰ� ���������ϱ�
				   visited[i][j-1]�� ���� ������ j-1�� ������ j-2���� ���۵� �Ŵϱ� ��������
*/