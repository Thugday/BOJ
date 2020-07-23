#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int i;
	char c[100];

	cin >> c;

	for (i = 0; i < 100; i++) {
		if (c[i] == '\0') {
			break;
		}
	}
	
	for (int j = 0; j < i; j++) {
		cout << c[j];
		if ((j + 1) % 10 == 0) {
			cout << "\n";
		}
	}
	
}