#include <iostream>
#include <vector>

using namespace std;

long long fib[21] = { 1 };
bool check[21];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 피보나치 구현.
	for (int i = 1; i <= 20; i++) {
		fib[i] = fib[i - 1] * i;
	}

	int n;
	cin >> n;

	int val;
	cin >> val;

	// 임의의 순열을 입력받아 몇번째 순열인지 체크해주기.
	if (val == 2) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		long long ans(0);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) {
				if (check[j] == false) {
					ans += fib[n - i - 1];
				}
			}
			check[v[i]] = true;
		}
		cout << ans + 1 << '\n';
	}

	// temp 번째의 순열을 구현해 주기.
	else if (val == 1) {
		long long temp;
		cin >> temp;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[j] == true) {
					continue;
				}
				if (fib[n - i - 1] < temp) {
					temp -= fib[n - i - 1];
				}
				else {
					v[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}