#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long d[100]; // 최대 수 : 90, int범위를 벗어나기 때문에 long long 사용.

	d[0] = 0; // 0일 때 0.
	d[1] = 1; // 1일 때 1.


	// 피보나치 수 : Fn = Fn-1 + Fn-2
	for (int i = 2; i <= 100; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	int n;
	cin >> n;

	cout << d[n] << '\n';
	return 0;
}