#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = n; i > 0; i--) { //감소하는 순으로 정렬
		cout << i << '\n';
	}

	return 0;
}