#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // n개의 값 입력 받기.
	}

	vector<int> b(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			b[i] = max(b[i], b[i - j] + a[j]); // i-j까지 a 값을 더해주며 max값을 구해줌.
		}
	}

	cout << b[n] << '\n';

	return 0;
}