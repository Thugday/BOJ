#include <iostream>
#include <cstring>
#define MAX 501

using namespace std;

int a[MAX][2];
int d[MAX][MAX];

int solve(int x, int y) {
	if (x == y) {
		return 0;
	}
	
	if (d[x][y]) {
		return d[x][y];
	}
	
	if (x + 1 == y) {
		return a[x][0] * a[x][1] * a[y][1];
	}
	
	int& ans = d[x][y];
	ans = -1;

	for (int i = x; i <= y - 1; i++) { // x 부터 y-1까지 for문.
		int temp = solve(x, i); // 중간에 i를 두어 x부터 i까지.
		int temp2 = solve(i + 1, y); // i+1부터 y까지.
		if (ans == -1 || ans > temp + temp2 + a[x][0] * a[i][1] * a[y][1]) {
			ans = temp + temp2 + a[x][0] * a[i][1] * a[y][1];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}

	cout << solve(0, n - 1) << '\n';
	return 0;
}