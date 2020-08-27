#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

// 연산자 오버로딩 사용.
matrix operator*(const matrix& a, const matrix& b) { 
	int n = a.size();
	matrix c(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long m;
	cin >> n >> m; // 행렬 크기 와 m 입력 받기.

	matrix ans(n, vector<int>(n));
	matrix x(n, vector<int>(n));

	for (int i = 0; i < n; i++) { // 행렬 원소 입력 받기.
		for (int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
		ans[i][i] = 1;
	}

	while (m > 0) { 
		if (m % 2 == 1) { // 홀수일 때.
			ans = ans * x;
		}
		x = x * x; // 짝수일 때.
		m /= 2;
	}

	// 정답 출력하기.
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
