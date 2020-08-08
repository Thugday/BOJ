#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[110][110];
int d[110][110];
bool check[110][110];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	// 최단거리를 구해야되기 때문에 bfs를 사용해 준다.
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	d[0][0] = 1; // 시작점.

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == false && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1; // 어떠한 칸까지의 거리.
					check[nx][ny] = true;
				}
			}
		}
	}
	printf("%d\n", d[n - 1][m - 1]); // 0,0 에서 n-1,m-1까지의 거리중 가장 빠른 답.
	return 0;
}