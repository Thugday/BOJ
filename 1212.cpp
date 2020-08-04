#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	// 2진수를 8진수로 바꿔줌. 세자리씩 끊어서 0~7까지의 값을 차례대로 바꿔주면 된다.
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			if (i == 0) {
				cout << '0';
			}
			else {
				cout << "000";
			}
		}
		else if (s[i] == '1') {
			if (i == 0) {
				cout << "1";
			}
			else {
				cout << "001";
			}
		}
		else if (s[i] == '2') {
			if (i == 0) {
				cout << "10";
			}
			else {
				cout << "010";
			}
		}
		else if (s[i] == '3')
		{
			if (i == 0) {
				cout << "11";
			}
			else {
				cout << "011";
			}
		}
		else if (s[i] == '4')
			cout << "100";
		else if (s[i] == '5')
			cout << "101";
		else if (s[i] == '6')
			cout << "110";
		else if (s[i] == '7')
			cout << "111";
	}
	return 0;
}