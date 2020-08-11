#include <iostream>

using namespace std;

int d[3000][3000];
int cnt[3];



bool same(int x, int y, int n) {
	// (x,y)부터 n 까지가 모두 같은지 안 같은지 구분해준다.
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (d[x][y] != d[i][j]) {
				return false; // 다르면 false.
			}
		}
	}
	return true; // 같으면 true.
}

void solve(int x, int y, int n) {
	// (x,y)부터 n개의 칸이 모두 같으면 cnt 에 1을 더해준다.
	if (same(x, y, n)) {
		cnt[d[x][y] + 1] += 1;
		return;
	}

	// 같지 않을 시 9칸으로 다시 나눠주고 solve 함수 다시 돌려주기.
	int m = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + i * m, y + j * m, m);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}

	solve(0, 0, n); // (0,0)부터 시작.

	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}