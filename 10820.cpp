#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	
	
	while (getline(cin, s)) { // 한 줄 입력 받기.
		int small(0), big(0), space(0), num(0);
		for (char x : s) {
			if (x >= 'a' && x <= 'z') {
				small += 1;	// 소문자 찾기 및 소문자 수량 증가
			}
			else if (x >= 'A' && x <= 'Z') {
				big += 1; // 대문자 찾기 및 대문자 수량 증가
			}
			else if (x >= '0' && x <= '9') {
				num += 1; // 숫자 찾기 및 숫자 수량 증가
			}
			else if (x == ' ') {
				space += 1; // 공백 찾기 및 공백 수량 증가
			}
		}
		cout << small << ' ' << big << ' ' << num << ' ' << space << '\n'; 
	}

	return 0;
}