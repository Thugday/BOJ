#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	int a, b;
	while (t--) {
		for (int i = 1; i <= t + 1; i++) {
			cin >> a >> b;
			int sum = a + b;
			cout << "Case #" << i << ": " << sum << '\n';
		}
		break;
	}
	
	return 0;
}