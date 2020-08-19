#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solve(vector<string> &v, vector<bool> &c, int x, int y) {
	int sol = 0;
	// 상,하,좌,우 이동.
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		// 보드의 크기를 넘지 않고 다음 칸의 알파벳을 방문하지 않았을 시. 
		if (nx >= 0 && nx < v.size() && ny >= 0 && ny < v[0].size()) {
			if (c[v[nx][ny] - 'A'] == false) {
				c[v[nx][ny] - 'A'] = true; // 방문 시켜주기.
				int next = solve(v, c, nx, ny);
				if (sol < next) {
					sol = next;
				}
				c[v[nx][ny] - 'A'] = false; // 초기화.
			}
		}
	}
	return sol + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<bool> c(26);
	c[v[0][0] - 'A'] = true;
	cout << solve(v, c, 0, 0) << '\n';
	return 0;
}