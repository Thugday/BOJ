#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001

using namespace std;

int a[MAX];
int d[MAX][31];
int t, w;

int solve(int pos, int move) {
	if (pos == t + 1 && move <= w) {
		return 0; // 더 이상 받을 열매가 없을 때.
	}

	if (move > w) {
		return 0; // 더 이상 움직일 수 없을 때.
	}

	if (d[pos][move] != -1) { // memorization.
		return d[pos][move];
	}

	int place = move % 2 + 1; // 사람 위치 구하기.
	int& ans = d[pos][move];
	ans = max(solve(pos + 1, move), solve(pos + 1, move + 1)) + (place == a[pos] ? 1 : 0); // 사람이 움직이지 않을 때, 사람이 움직일때 + 열매를 받을 때.
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> t >> w;

	for (int i = 1; i <= t; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));
	
	int sol = max(solve(1, 0), solve(1, 1)); // 1번 나무에서 시작하는 경우, 2번 나무에서 시작하는 경우로 나눠서 시작해줌.
	cout << sol << '\n';
	return 0;
}