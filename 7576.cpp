#include <iostream>
#include <queue>

using namespace std; 

// 최대 1000.
int a[1010][1010];
int d[1010][1010];

// 상, 하, 좌, 우 확인 배열.
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> m >> n;

	// bfs 사용.
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			d[i][j] = -1;
			if (a[i][j] == 1) {
				q.push(make_pair(i, j)); // 익은 토마토 넣어주기.
				d[i][j] = 0; // 방문으로 체크.
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (a[nx][ny] == 0 && d[nx][ny] == -1) { // 익지 않았으면서 방문하지 않은 곳.
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sol < d[i][j]) {
				sol = d[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && d[i][j] == -1) {
				sol = -1;
			}
		}
	}

	cout << sol << '\n';

	return 0;
}