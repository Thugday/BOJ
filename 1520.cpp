#include <iostream>
#include <cstring>
#define MAX 501

using namespace std;

int n, m;

int d[MAX][MAX];
int a[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solve(int x, int y) {
	if (x == n - 1 && y == m - 1) {
		return 1; // (0,0) 에서 는 (n-1,m-1) 한 가지.
	}
	if (d[x][y] != -1) {
		return d[x][y]; // 값이 중복될 경우.
	}

	int &ans = d[x][y];
	ans = 0;

	for (int k = 0; k < 4; k++) { // 상 하 좌 우의 움직임 구현.
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) { // 범위를 체크해준다.
			if (a[x][y] > a[nx][ny]) { // 값이 더 작은지 확인해 주고 작다면 답에 넣어주기.
				d[x][y] += solve(nx, ny);
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	memset(d, -1, sizeof(d));
	cout << solve(0, 0);
	return 0;
}