#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int arr[101], T, N;
int visited[10001];
int solve() {
	vector<int> v;
	v.push_back(0);

	for (int i = 0; i < N; i++) {
		//	vec��ȯ
		int len = v.size();
		//!! v.size()�� for���� �������� �ɾ����� ���ѷ���**�����ϱ�**
		for (int j = 0; j < len; j++) {
			// ���Ͱ��� �� ���� - �������� ������� ����
			int n = v[j] + arr[i];
			
			if (!visited[n]) {
				//cout << n << endl;
				visited[n] = true;
				v.push_back(n);
			}
		}
	}

	return v.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		
		cout << "#"<<t<<" "<<solve() << "\n";

		memset(visited, 0, sizeof(visited));

	}
	return 0;
}

/*
������
- ������ �������� dfs�� ������� �ߴµ� �� �ȵȴ�....
- ���� ������ Ŀ�� �� ���Ƽ� set�� �ϳ� ���� ó���ϰ��� �ߴµ� �ȵ�..->��� �ߺ� ���
- dfs�� �� idx�� depth�� �����ϴ°� ��ƴ�
- dfs�Ҷ��� �ִ� 100�̱� ������ O(2^100)�̶� �ð��ʰ�

�ذ��
- 2�� for������ ������ ��������
- �ִ� ������ 100(�ִ� ����) * 100(�ִ� ����) => 10000���̶�°� Ȱ��
- vector�� ���ο� ���� �߰��ϸ鼭 flag�� �Ŵ� ����

�����µ� ��ư� �����ߴ�.. �θ�Ʈ������ �����ϴ� ����� ����߰ڴ�
*/