#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;

	string s = to_string(a) + to_string(b); // int value a와 b를 string(s)으로 붙여서 저장해주기.
	string s2 = to_string(c) + to_string(d); // int value c와 d를 string(s2)으로 붙여서 저장해주기.

	long long num1 = stoll(s); // 바꾼 string value를 다시 long long value로 바꿔주기.
	long long num2 = stoll(s2); // 바꾼 string value를 다시 long long value로 바꿔주기.

	cout << num1 + num2 << '\n'; // 두 long long value를 더해서 출력해주기.

	return 0;
}