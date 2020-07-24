#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for( int j = 1; j <= n - i; j++) {
			cout << " ";
		}
		if (i == 1 || i == n) {
			for (int k = 1; k <= (i - 1) * 2 + 1; k++) {
				cout << "*";
			}
		}
		else {
			cout << "*";
			for (int j = 1; j <= (i - 1) * 2 - 1; j++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}