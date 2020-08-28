// Fn+2 - 1의 피보나치수의 합을 이용.
#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000000; // 10억으로 나눠준 수를 구하기 위한 mod.
typedef vector<vector<long long>> matrix;

matrix operator*(matrix a, matrix b) {
	matrix m(2, vector<long long>(2));
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			long long sum = 0;
			for (int k = 0; k < 2; k++) {
				sum += ((a[i][k] % mod) * (b[k][j] % mod)) % mod;
			}
			m[i][j] = sum % mod;
		}
	}
	return m;
}

// 행렬을 곱해주기 위한 function 구현.
matrix calc(matrix a, long long b) {
	if (b == 0) {
		matrix m(2, vector<long long>(2));
		m[0][0] = 1;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 1;
		return m;
	}
	else if (b % 2 == 0) { // 짝수일 때.
		matrix temp = calc(a, b / 2);
		return temp * temp;
	}
	else { // 홀수일 때.
		matrix temp = calc(a, b - 1);
		return a * temp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	
	long long ans = 0;

	matrix x(2, vector<long long>(2));
	x[0][0] = 1;
	x[0][1] = 1;
	x[1][0] = 1;
	x[1][1] = 0;
	matrix B = calc(x, m + 2);
	matrix A = calc(x, (n - 1) + 2);
	ans = ((B[0][1] - 1) % mod - (A[0][1] - 1) % mod + mod) % mod; // 음수 방지.

	cout << ans << '\n';
	return 0;
}