#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	cout << s.length() << '\n'; // length를 사용 해 단어길이 재주기.

	return 0;
}