#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;

	cin >> a >> b >> c; // 세 수 입력 받기.

	if (a < 0 || b < 0 || c < 0 || a > 100 || b > 100 || c > 100) {
		return 0;
	} // 범위에서 out of range 일 시 리턴 값 0.

	int large = max({ a, b, c }); // 제일 큰 수.
	int small = min({ a, b, c }); // 제일 작은 수.

	if (b == c && a != b) {
		cout << b;
	}
	if (a != large && a != small) {
		cout << a; // a 값이 중간 값일 때.
	}
	if (b != large && b != small) {
		cout << b; // b 값이 중간 값일 때.
	}
	if (c != large && c != small) {
		cout << c; // c 값이 중간 값일 때.
	}
	if (a == b == c) {
		cout << a; // 모두 같으면 셋 중 하나 출력.
	}
	if (a == b || a == c && !(a == b == c) ){
		cout << a;
	}

	return 0;
}