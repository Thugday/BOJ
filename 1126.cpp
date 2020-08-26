#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 10000000;
int a[50];
int d[50][250001]; // 한 탑의 최대 높이는 25만.
int n;

int solve(int x, int y) {
	if (y > 250000) { // 높이의 차이가 25만 보다 크면 불가능 하다.
		return -inf;
	}

	if (x == n && y) { // 조각을 모두 사용했지만 불가능할 때.
			return -inf;
	}

	if (x == n && y == 0) { // 높이의 차가 0일때 모든 조각을 사용했다면 0 리턴.
		return 0;
	}

	int& ans = d[x][y];
	if (ans != -1) {
		return ans;
	}

	ans = solve(x + 1, y); // 조각을 사용하지 않는경우.
	ans = max(ans, solve(x + 1, y + a[x])); // 높은 탑에 조각을 놓는 경우.

	// 두탑의 높이의 차이와 조각의 크기를 비교해서 낮은 탑에 조각을 놓는 경우.
	if (a[x] > y) {
		ans = max(ans, y + solve(x + 1, a[x] - y));
	}
	else {
		ans = max(ans, a[x] + solve(x + 1, y - a[x]));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));
	int ans = solve(0, 0);
	if (ans == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;
}