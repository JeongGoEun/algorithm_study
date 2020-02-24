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
문제점
1 - 출력형식 잘못봐서 틀림(갯수 구하는거)
2
vector 사이즈로 계산할 때 : 14294KB, 184ms
pow로 미리 사이즈 계산할 때: 2168KB, 180ms

시간은 별로 차이 안나지만 메모리 차이가 엄청나다
*/