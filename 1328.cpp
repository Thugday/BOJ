#include <iostream>
#define MAX 101

using namespace std;

long long d[MAX][MAX][MAX];
long long mod = 1000000007LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, l, r;
	cin >> n >> l >> r;

	d[1][1][1] = 1LL;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				// 가장 왼쪽 빌딩에 1이 있는 경우 : d[i-1][j-1][k]
				// 가장 오른쪽 빌딩에 1이 있는 경우 : d[i-1][j][k-1]
				// 빌딩 사이에 1이 있는 경우 : d[i-1][j][k] * (i-2)
					d[i][j][k] = d[i - 1][j - 1][k] + d[i - 1][j][k - 1] + d[i - 1][j][k] * (i - 2);
					d[i][j][k] %= mod;
			}
		}
	}
	cout << d[n][l][r] << '\n';
	return 0;
}