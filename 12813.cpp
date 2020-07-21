#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1, s2; 
	cin >> s1 >> s2; //문자열로 bit string을 입력 받음.

	bitset<100000> b1(s1), b2(s2);
	cout << (b1 & b2) << '\n';
	cout << (b1 | b2) << '\n';
	cout << (b1 ^ b2) << '\n';
	cout << (~b1) << '\n';
	cout << (~b2) << '\n';

	return 0;
}