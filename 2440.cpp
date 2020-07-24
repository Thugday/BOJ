#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = n - i; j >= 0; j--) { // 감소하는 식의 *찍기
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}