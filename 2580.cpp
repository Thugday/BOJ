#include <iostream>
#include <cstdlib>

using namespace std;

int d[10][10];
int n(9);
bool a[10][10];
bool b[10][10];
bool c[10][10];

int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

void solve(int z) {
	if (z == 81) {
		// 체크해주기.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << d[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = z / n, y = z % n;
	if (d[x][y] != 0) {
		solve(z + 1);
	}
	// x행 y열에 들어갈 수 있는 수를 확인해준다.
	else {
		for (int i = 1; i <= 9; i++) {
			if (a[x][i] == 0 && b[y][i] == 0 && c[square(x, y)][i] == 0) {
				a[x][i] = b[y][i] = c[square(x, y)][i] = true; // 들어갈 수 있을 때.
				d[x][y] = i;
				solve(z + 1);
				d[x][y] = 0;
				a[x][i] = b[y][i] = c[square(x, y)][i] = false; // 들어갈 수 없을 때.
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
			if (d[i][j] != 0) {
				a[i][d[i][j]] = true; // a[i]행에 d[i][j]가 있을 시 true.
				b[j][d[i][j]] = true; // b[j]열에 d[i][j]가 있을 시 true.
				c[square(i, j)][d[i][j]] = true; // 정사각형 i,j에 d[i][j]가 있을 시 true. 
			}
		}
	}
	solve(0);

	return 0;
}