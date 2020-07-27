#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;

	cin >> s; // 단어 입력 받기.

	for (int i = 'a'; i <= 'z'; i++) {
		cout << count(s.begin(), s.end(), i) << ' ';
	} // 소문자로 이루어진 단어의 알파벳 갯수 찾아주기.
	
	cout << '\n';

	return 0;
}
