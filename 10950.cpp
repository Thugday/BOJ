#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		int sum = a + b;
		cout << sum << '\n';
	}

	return 0;
}