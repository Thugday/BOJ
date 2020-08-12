#include <iostream>
#include <string>
#define MAX 65

using namespace std;

int d[MAX][MAX];

void solve(int n, int y, int x) {
	if (n == 1) {
		cout << d[y][x];
		return;
	}

	bool zero = true, one = true;

	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (d[i][j]) {
				zero = false;
			}
			else {
				one = false;
			}
		}
	}

	if (zero) {
		cout << 0;
	}
	else if (one) {
		cout << 1;
	}
	else {
		// 4개의 영역을 나눠서 다시 solve 함수에 넣어준다.
		cout << "(";
		solve(n / 2, y, x);
		solve(n / 2, y, x + n / 2);
		solve(n / 2, y + n / 2, x);
		solve(n / 2, y + n / 2, x + n / 2);
		cout << ")";
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	bool zero = true;
	bool one = true;

	for (int i = 0; i < n; i++) {
		string s; // string으로 입력 받기.
		cin >> s;

		for (int j = 0; j < n; j++) {
			d[i][j] = s[j] - '0';
		}
	}

	solve(n, 0, 0);
	cout << '\n';

	return 0;
}