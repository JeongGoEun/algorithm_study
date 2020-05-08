#include<iostream>
#include<vector>
#include<set>
using namespace std;
int N, S, arr[20], ans;
bool visited[20];

void dfs(int idx, int sum) {
	// ���ݱ����� �κм��� �հ� + ���簡 0�̶��
	//cout << sum << endl;
	if (idx == N) {
		// sum==s�� ������ ������ �ʰ� �κм����� ������ ��������ٰ� ����
		// -> cnt�� ó���� ���� �� �ʿ䰡 ����
		if (sum == S) {
			ans++;
		}
		return;
	}


	//�ش� ���Ҹ� ���� �ϰų�, ���� �ʰų�
	dfs(idx + 1, sum + arr[idx]);
	dfs(idx + 1, sum);
}
int main() {
	ios::sync_with_stdio(0);	cin.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);

	// �������� ��� S�� 0�̸� �ϳ��� �߰��Ǳ� ������ ���� ó��
	if (S == 0) {
		ans--;
	}
	cout << ans;
	return 0;
}
