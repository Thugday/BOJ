#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 201

using namespace std;

bool check[MAX][MAX];
bool v[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;

	int sum = c;

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	v[c] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y; // x+y+z = sum.
		q.pop();
		int nx, ny, nz;

		nx = x;
		ny = y;
		nz = z;

		// x에서 y로 붓기.
		ny += nx;
		nx = 0;
		if (ny >= b) {
			nx = ny - b;
			ny = b;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				v[nz] = true;
			}
		}

		nx = x;
		ny = y;
		nz = z;

		// x에서 z로 붓기.
		nz += nx;
		nx = 0;
		if (nz >= c) {
			nx = nz - c;
			nz = c;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				v[nz] = true;
			}
		}

		nx = x;
		ny = y;
		nz = z;

		// y에서 x로 붓기.
		nx += ny;
		ny = 0;
		if (nx >= a) {
			ny = nx - a;
			nx = a;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				v[nz] = true;
			}
		}

		nx = x;
		ny = y;
		nz = z;

		// y에서 z로 붓기.
		nz += ny;
		ny = 0;
		if (nz >= c) {
			ny = nz - c;
			nz = c;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				v[nz] = true;
			}
		}

		nx = x;
		ny = y;
		nz = z;

		// z에서 x로 붓기.
		nx += nz;
		nz = 0;
		if (nx >= a) {
			nz = nx - a;
			nx = a;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				v[nz] = true;
			}
		}

		nx = x;
		ny = y;
		nz = z;

		// z에서 y로 붓기.
		ny += nz;
		nz = 0;
		if (ny >= b) {
			nz = ny - b;
			ny = b;
		}

		if (!check[nx][ny]) {
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0) {
				v[nz] = true;
			}
		}
	}

	for (int i = 0; i <= c; i++){
		if (v[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
	return 0;
}