#include <iostream>

using namespace std;

void negative(int n) { // 재귀함수 구현, -2진수 구하기.
	if (n == 0) { // n이 0인 경우.
		return;
	}
	if (n % 2 == 0) { // 짝수일 경우.
		negative(-(n / 2));
		cout << "0";
	}
	else { // 홀수일 경우
		if (n > 0) {
			negative(-(n / 2)); // n이 양수인 경우.
		}
		else {
			negative((-n + 1) / 2); // n이 음수인 경우.
		}
		cout << "1";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	if (n == 0) {
		cout << "0" << '\n';
	}
	else {
		negative(n);
	}

	return 0;
}