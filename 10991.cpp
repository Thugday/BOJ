#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= 2 * i - 1; k++) {
			if (k % 2 == 1) { // 홀수 자리에 * 찍어주기.
				cout << "*";
			}
			else {
				cout << " "; // 짝수 자리에 공백.
			}
		}
		cout << "\n";
	}

	return 0;
}