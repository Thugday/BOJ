#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	// 8진수를 2진수로 바꿔줌. string으로 입력받아 앞 숫자부터 차례대로 2진수로 바꿔준다.
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