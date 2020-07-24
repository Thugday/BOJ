#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) { // n까지의 i행
		for (int j = 1; j <= i; j++) { // i까지의 j행 * 한 개씩 증가
			cout << "*";
		}
		cout << '\n';
	}

	return 0;
}