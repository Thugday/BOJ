#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char BLANK = ' ';
const char STAR = '*';

void solve(vector<vector<char>>& v, int x, int y, int n, char space) {
	if (space == BLANK) {
		int m = 2 * n - 1;
		for (int i = x; i < x + n; i++) {
			for (int j = 0; j < m; j++) {
				v[i][j+i-x+y] = BLANK;
			}
			m -= 2;
		}
	}
	else if(space == STAR){
		if (n != 1) {
			int m = n / 2;
			solve(v, x, y, m, STAR);
			solve(v, x + m, y - m, m, STAR);
			solve(v, x + m, y + m, m, STAR);
			if (n == 3) {
				solve(v, x + 1, y, 1, BLANK);
			}
			else {
				solve(v, x + m, y - m + 1, m, BLANK);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<char>> v(n, vector<char>(2*n, STAR));
	solve(v, 0, n-1, n, STAR);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			v[i][j] = BLANK;
			v[i][2 * n - j - 2] = BLANK;
		}
		v[i][2 * n - 1] = BLANK;
	}
	
	for (int i = 0; i < n; i++) {
		cout << string(v[i].begin(), v[i].end()) << '\n';
	}
	return 0;
}