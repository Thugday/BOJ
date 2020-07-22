#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	for (int i = 'a'; i <= 'z'; i++) { // 소문자 범위 설정.
		auto it = find(s.begin(), s.end(), i); // string에 들어가는 알파벳 위치 찾기
		if (it == s.end()) {
			cout << -1 << '\n'; // 알파벳이 포함되지 않으면 -1 출력.
		}
		else {
			cout << (it - s.begin()) << '\n';
		}
	}

	cout << '\n';
	return 0;
}