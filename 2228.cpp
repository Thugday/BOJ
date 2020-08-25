#include <iostream>
#define MAX 101

using namespace std;

int a[MAX];
bool b[MAX][MAX];
int d[MAX][MAX];
int min_value = -32768*MAX;

int solve(int n, int m) {
	if (m == 0) { // m 개의 구간이 모두 있다.
		return 0;
	}

	if (n <= 0) {
		return min_value; // 더 이상 사용할 수 없을 때, m > 0(m개보다 작음).
	}

	if (b[n][m]) { // memorization.
		return d[n][m];
	}

	b[n][m] = true;
	int& ans = d[n][m];
	ans = solve(n - 1, m); // n을 포함하지 않는경우.

	int sum = 0;
	for (int i = n; i >= 1; i--) { // n을 포함하는 경우.
		sum += a[i];
		int temp = solve(i - 2, m - 1) + sum;
		if (ans < temp) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << solve(n, m) << '\n';
	return 0;
}