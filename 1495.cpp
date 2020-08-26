#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, s, m;
int v[101];
int d[1001][101];

int solve(int vol, int num) {
	if (vol < 0 || vol > m) {
		return -100;
	}
	if (num == n) {
		return vol; // memorization.
	}
	int& ans = d[vol][num];

	if (ans != -1) {
		return ans;
	}
	// v[num+1] 만큼 더할 경우와 뺄경우의 max.
	return ans = max(solve(vol + v[num + 1], num + 1), solve(vol - v[num + 1], num + 1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	//곡의 수, 시작 볼륨, 최대 볼륨 입력 받기.
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	memset(d, -1, sizeof(d));
	int ans = solve(s, 0);
	if (ans == -100) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}