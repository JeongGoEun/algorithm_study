#include<iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input="";
	cin >> input;

	int sum = 0,idx=0;
	string n = "";
	bool minus = false;

	for (int i = 0; i <= input.size(); i++) {
		// string 마지막은 \0
		if (input[i] == '+' || input[i] == '-' || input[i]=='\0') {
			if (minus)	//빼기였으면 빼주기
				sum -= stoi(n);
			else // 플러스였으면 더해주기
				sum += stoi(n);
			n = "";
			if (input[i] == '-') {
				minus = true;
			}
			continue;
		}
		n += input[i];
	}
	cout << sum;
	return 0;
}