#include<iostream>
#include<bitset>
using namespace std;
int main() {
	bitset<100000> A, B;
	cin >> A >> B;
	cout << (A & B) << "\n";
	cout << (A | B) << "\n";
	cout << (A ^ B) << "\n";
	cout << ~(A) << "\n";
	cout << ~(B) << "\n";

	return 0;
}