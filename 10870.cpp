#include <iostream>
#include <functional>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	function<int(int)> f = [&](int n) {
		if (n <= 1) {
			return n;
		}
		else {
			return f(n - 1) + f(n - 2);
		}
	};

	cout << f(n) << '\n';
	return 0;
}