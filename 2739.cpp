#include <iostream>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	
	while (1 <= n && n <= 9) {
		for (int i = 1; i <= 9; i++) {
			cout << n << " * " << i << " = " << (n * i) << "\n";
		}
		break;
	}
	
	return 0;
}