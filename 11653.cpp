#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 2부터 루트 N까지 for문 돌리기, N으로 나눌수 있으면 나눌수 없을 때까지 계속 나눠주기
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}

	// 루트 N 보다 큰 인수는 하나 밖에 없다.
	if (n > 1) {
		cout << n << '\n';
	}

	return 0;
}