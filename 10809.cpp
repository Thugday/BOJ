#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	for (int i = 'a'; i <= 'z'; i++) {
		auto it = find(s.begin(), s.end(), i); // find 함수를 사용해 포함되어 있는 함수 중 i의 이터레이터 찾기.
		if (it == s.end()) { // 없다면 end를 return, -1을 출력.
			cout << -1 << ' ';
		}
		else { // 있다면 알파벳의 위치를 찾아준다.
			cout << (it - s.begin()) << ' '; 
		}
	}

	cout << '\n';

	return 0;
}