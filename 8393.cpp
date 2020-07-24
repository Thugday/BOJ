#include <iostream>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int sum(0);
	cin >> n;

	for (int i = 0; i <= n; i++) {
		sum += i; // n까지 계속 더해주기.
	}

	cout << sum;

	return 0;
}