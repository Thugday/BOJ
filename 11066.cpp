#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 501
using namespace std;

int a[MAX];
int b[MAX];
int d[MAX][MAX];

int solve(int x, int y) {
	if (x == y) { // x 와 y가 같을 때 0. 
		return 0;
	}
	if (d[x][y] != -1) { // 값이 중복 될 때.
		return d[x][y];
	}

	int& ans = d[x][y];

	for (int i = x; i <= y - 1; i++) { // x 부터 y-1까지 for 문.
		int temp = solve(x, i) + solve(i + 1, y) + b[y] - b[x - 1]; // 최소값 구하기 다이나믹으로 구현.
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		memset(d, -1, sizeof(d));
		memset(b, 0, sizeof(b));
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) { // 1부터 n 까지 합치는 비용.
			cin >> a[i];
			b[i] = b[i - 1] + a[i];
		}
		cout << solve(1, n) << '\n';
	}
	return 0;
}