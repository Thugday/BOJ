#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x(0);
	int n;
	cin >> n;

	// 팩토리얼의 0의 개수를 정해주는것은 팩토리얼 수의 소인수 중 5의 값이 되므로,
	// 5부터 5의 제곱수들을 나눠준다.
	for (int i = 5; i <= n; i *= 5) {
		x += n / i;
	}

	cout << x << '\n';
	return 0;
}	