#include <iostream>
#include <algorithm>
#define MAX 101

using namespace std;

int a[MAX][MAX];
long long d[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// (0,0) 시작.
	d[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) {
				continue; // 예외처리.
			}
			for (int k = 0; k < j; k++) {
				// j - k = a[i][k], 맞으면 d[i][k]를 더해줌.
				if (k + a[i][k] == j) {
					d[i][j] += d[i][k];
				}
			}
			// i- k = a[k][j], 맞으면 d[k][j] 더해주기.
			for (int k = 0; k < i; k++) {
				if (k + a[k][j] == i) {
					d[i][j] += d[k][j];
				}
			}
		}
	}

	cout << d[n - 1][n - 1] << '\n';
	return 0;
}