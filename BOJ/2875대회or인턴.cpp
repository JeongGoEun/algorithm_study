#include<iostream>
using namespace std;
int N, M, K,ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	// ����2�� �̻�, ���� 1�� �̻� , �������>=������ ��� + �� �� �̻�
	while ((N>=2 && M>=1) && (N+M >= 3+K))
	{
		N -= 2;
		M -= 1;
		ans++;
	}
	cout << ans;
	return 0;
}
/*
����1
- ���л��� �������� n-2, m-1�� �ϸ鼭 k���� �۾��� �� �ߴ��ϴ� ���

*/