#include <iostream>

using namespace std;

// 팩토리얼 구해주기.
int getFactorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * getFactorial(n - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	getFactorial(n);

	cout << getFactorial(n) << '\n';

	return 0;
}