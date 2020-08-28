#include <iostream>

using namespace std;

int fibonacci(int n) {
	int d[47]; // 최대 수 45.

	d[0] = 0; // 0일 때 0.
	d[1] = 1; // 1일 때 1.

	// 피보나치 수 : Fn = Fn-1 + Fn-2
	for (int i = 2; i < 47; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}

	return d[n];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; 
	cin >> n; // 수 입력받기.

	cout << fibonacci(n) << '\n';
	return 0;
}