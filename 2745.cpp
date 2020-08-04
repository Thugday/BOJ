#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n(0), b;
	
	string s = "";

	cin >> s >> b;
	
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			n = n * b + (s[i] - '0'); // n의 수를 b진법이니 b로 곱해주면서 size만큼 계속 더해준다.
		}
		else {
			n = n * b + (s[i] - 'A' + 10);
		}
	}

	cout << n << '\n';

	return 0;
}