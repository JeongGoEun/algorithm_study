#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N,ans;
struct Node {
	int from, to;
};
vector<Node> v;
void hanoi(int from, int to, int n) {
	if (n == 0) {
		return;
	}
	hanoi(from, 6 - from - to, n - 1);
	//v.push_back({ from,to });
	cout << from << " " << to << "\n";
	hanoi(6 - from - to, to, n - 1);
}
int main() {
	cin >> N;

	cout << (int)pow(2, N)-1 << "\n";
	hanoi(1, 3, N);
	/*cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].from << " " << v[i].to << "\n";
	}*/
	return 0;
}
/*
������
1 - ������� �߸����� Ʋ��(���� ���ϴ°�)
2
vector ������� ����� �� : 14294KB, 184ms
pow�� �̸� ������ ����� ��: 2168KB, 180ms

�ð��� ���� ���� �ȳ����� �޸� ���̰� ��û����
*/