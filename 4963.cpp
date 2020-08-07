#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int w[60][60];
int l[60][60];

int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 }; // 대각선을 포함해 확인해줄 1차원 배열.
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 }; // 대각선을 포함해 확인해줄 1차원 배열.

int n, m;

void bfs(int x, int y, int count) { // bfs 구현.
	queue<pair<int, int>> q; // queue, pair 사용.
	q.push(make_pair(x, y));
	l[x][y] = count;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (w[nx][ny] == 1 && l[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					l[nx][ny] = count;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0) { // 초기화.
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> w[i][j];
				l[i][j] = 0;
			}
		}
		int count(0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (w[i][j] == 1 && l[i][j] == 0) {
					bfs(i, j, ++count);
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}