#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int small(0), big(0), num(0), space(0);
	string s;

	while (getline(cin, s)) { //getline 을 사용해 한 줄을 모두 입력.
		for (char x : s) {
			if (x >= 'a' && x <= 'z') { // 소문자
				small += 1;
			}
			else if ( x >= 'A' && x <= 'Z'){ // 대문자
				big += 1;
			}
			else if (x >= '0' && x <= '9') { // 숫자
				num += 1;
			}
			else if (x == ' ') { //공백
				space += 1;
			}
		}
		cout << small << " " << big << " " << num << " " << space;
	}
	return(0);
}