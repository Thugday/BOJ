#include <iostream>
#include <cstring>
#define MAX 2001

using namespace std;

int a[MAX];
int d[MAX][MAX];

// 팰린드롬을 구할 재귀함수 구현.
int solve(int i, int j) {
	if (i == j) { // 길이가 1일 때.
		return 1;
	}

	// 길이가 2일 때.
	else if (i + 1 == j) { 
		if (a[i] == a[j]) {
			return 1;
		}
		else {
			return 0;
		}
	}

	// memorization.
	if (d[i][j] != -1) {
		return d[i][j];
	}
	if (a[i] != a[j]) { // a[i] 와 a[j] 가 다르면 0.
		return d[i][j] = 0;
	}
	else {
		return d[i][j] = solve(i + 1, j - 1); // 같으면 다음 수에 대해 조사.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(d, -1, sizeof(d));
	int m;
	cin >> m;

	while (m--) {
		int b, c;
		cin >> b >> c;
		cout << solve(b - 1, c - 1) << '\n';
	}
	return 0;
}