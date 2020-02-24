#include<iostream>
using namespace std;
int N;
long long S, arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;

	// �κ��� ���ϱ�
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	long long sum=arr[1];
	int l = 1, r = 1, MIN = 100009;

	while (l <= r && r <= N) {
		if (sum < S) {
			r += 1;
			sum += arr[r];
		}
		else {
			MIN = r - l + 1 < MIN ? r - l + 1 : MIN;
			sum -= arr[l];	
			l += 1;
		}
	}
	// MIN���� �״�ζ�� -> �Ұ����� ���
	MIN = MIN == 100009 ? 0 : MIN;

	cout << MIN;
	return 0;
}

/*
������
- �κ����� �켱���� ���ϰ� i, j������ ���Ͽ� �κ����� ���ϴ� ����for���� ���ȴ��� �ð��ʰ�
- ���� �� �б�(S�̻��ε� S�� ������ �����ؼ� Ʋ��)

�ذ� ��� - �������� ����� ����Ѵ�. -> �������� ������� �������� ������.
- S���� ���� �����Ǳ� ������ �κ����� ���ϰ� ���� �ð� ����
- ���� ���� ���ϴ� ������ �ǵ����̸� �������� ����� ��������.
*/