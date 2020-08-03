#include <iostream>

using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c; // input 3개 입력 받기.

	int form1, form2, form3, form4;
	form1 = (a + b) % c; // 더하기 일때의 나머지 연산 1.
	form2 = ((a % c) + (b % c)) % c; // 더하기 일때의 나머지 연산 2.
	form3 = (a * b) % c; // 곱하기 일때의 나머지 연산 1.
	form4 = ((a % c) * (b % c)) % c; // 곱하기 일때의 나머지 연산 2.

	cout << form1 << '\n';
	cout << form2 << '\n';
	cout << form3 << '\n';
	cout << form4 << '\n';

	return 0;
}