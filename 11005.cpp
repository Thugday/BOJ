#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, b;
	cin >> n >> b; // 10진법 수 N과 바꿔줄 B진법수 B input받기.

	string s = "";

	while (n > 0) { // n을 계속 b로 나눠 줘야 하기 때문에 while문을 사용.
		int x = n % b;
		if (x < 10) { // 숫자로 나타낼 경우.
			s += (char)(x + '0');
		}
		else { // 10진법 이상은 문자로 표현.
			s += (char)(x - 10 + 'A');
		}
		n /= b;
	}
	reverse(s.begin(), s.end()); // 뒤에서 부터 출력해줘야 되기 때문에 reverse 사용.
	cout << s << '\n';

	return 0;
}