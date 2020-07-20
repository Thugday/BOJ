#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	while (1) {
		for (int i = 1; i <= n; i++) {
			cout << i << "\n";
		}
		break; //while 문 break
	}

	return 0;
}