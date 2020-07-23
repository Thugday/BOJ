#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;

	while (true) {
		getline(cin, s); // 한 줄 모두 입력 받기.
		if (s == "") {
			break;
		}
		cout << s << "\n";
	}

	return 0;
}