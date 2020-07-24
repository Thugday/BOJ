#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, j;

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (j = 0; j < i; j++) { // 공백은 증가 순
			cout << " ";
		}
		for (j = n; j > i; j--) { // *은 감소 순
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}