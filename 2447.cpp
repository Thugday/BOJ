#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char BLANK = ' ';
const char STAR = '*';

void solve(vector<vector<char>>& v, int x, int y, int n, char space) {
	if (space == BLANK) {
		for (int i = x; i < x + n; i++) {
			for (int j = y; j < y + n; j++) {
				v[i][j] = BLANK;
			}
		}
	}
	else {
		if (n == 1) { // n = 1 이면 별을 찍어준다.
			v[x][y] = STAR;
		}
		else { // 나머지의 경우 newSpace를 생성하여 빈칸을 채울지 별을 채울지 정해준다.
			char newSpace = STAR;
			int m = n / 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) {
						newSpace = BLANK;
					}
					else {
						newSpace = STAR;
					}
					solve(v, x + m * i, y + m * j, m, newSpace); // 재귀를 통해 다시 함수에 넣어주기.
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<char>> v(n, vector<char>(n, 0));
	solve(v, 0, 0, n, STAR);

	for (int i = 0; i < n; i++) {
		cout << string(v[i].begin(), v[i].end()) << '\n';
	}

	return 0;
}