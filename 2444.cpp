#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++){
			cout << " ";
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << "*";
		}
		cout << '\n';
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int k = i; k < n * 2 - 1 - i; k++) {
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}