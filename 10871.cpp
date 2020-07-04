#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x;

	cin >> n >> x;

	auto a = [&](int number) {
		return number < x;
	};

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (a(num)) {
			cout << num << ' ';
		}
	}
	cout << '\n';
}