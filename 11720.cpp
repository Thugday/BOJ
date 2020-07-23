#include <iostream>

using namespace std;

int main() {
	int n, sum(0);
	char s;

	cin >> n;

	while (1 <= n <= 100) {
		for (int i = 0; i < n; i++) {
			cin >> s;
			sum += (s - '0');
		}
		break;
	}

	cout << sum;

	return 0;
	
}