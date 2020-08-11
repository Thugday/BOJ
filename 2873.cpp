#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1001

using namespace std;

int d[MAX][MAX];

void addition(string& s, char c, int count) {
	for (int i = 0; i < count; i++) {
		s += c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int r, c;
	cin >> r >> c; // 행, 열 입력 받기.

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> d[i][j]; // 기쁨 입력 받기.
		}
	}

	string s = "";

	if (r % 2 == 1) { // 홀수인 경우
		for (int i = 0; i < r; i++) {
			if (i % 2 == 0) {
				addition(s, 'R', c - 1); // 오른쪽
				if (i != r - 1) {
					addition(s, 'D', 1); // 아래쪽
				}
			}
			else {
				addition(s, 'L', c - 1); // 왼쪽
				addition(s, 'D', 1); //아래쪽
			}
		}
	}
	else if (c % 2 == 1) { // 홀수인 경우
		for (int j = 0; j < c; j++) {
			if (j % 2 == 0) {
				addition(s, 'D', r - 1); // 아래쪽
				if (j != c - 1) {
					addition(s, 'R', 1); // 오른쪽
				}
			}
			else {
				addition(s, 'U', r - 1); // 위쪽
				addition(s, 'R', 1); // 오른쪽
			}
		}
	}
	else { // 짝수인 경우.
		int x(0), y(1);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((i + j) % 2 == 1) {
					if (d[x][y] > d[i][j]) {
						x = i;
						y = j;
					}
				}
			}
		}

		int temp_x(0), temp_y(0), temp_x2(r-1), temp_y2(c-1);
		string s2 = "";

		// 배열의 크기를 축소시켜준다.
		while (temp_x2 - temp_x > 1) {
			if (temp_x / 2 < x / 2) {
				addition(s, 'R', c - 1);
				addition(s, 'D', 1);
				addition(s, 'L', c - 1);
				addition(s, 'D', 1);
				temp_x += 2;
			}
			if (x / 2 < temp_x2 / 2) {
				addition(s2, 'R', c - 1);
				addition(s2, 'D', 1);
				addition(s2, 'L', c - 1);
				addition(s2, 'D', 1);
				temp_x2 -= 2;
			}
		}

		while (temp_y2 - temp_y > 1) {
			if (temp_y / 2 < y / 2) {
				addition(s, 'D', 1);
				addition(s, 'R', 1);
				addition(s, 'U', 1);
				addition(s, 'R', 1);
				temp_y += 2;
			}
			if (y / 2 < temp_y2 / 2) {
				addition(s2, 'D', 1);
				addition(s2, 'R', 1);
				addition(s2, 'U', 1);
				addition(s2, 'R', 1);
				temp_y2 -= 2;
			}
		}
		// 2x2까지 축소 시켜준다.
		if (y == temp_y) {
			addition(s, 'R', 1);
			addition(s, 'D', 1);
		}
		else {
			addition(s, 'D', 1);
			addition(s, 'R', 1);
		}
		reverse(s2.begin(), s2.end());
		s += s2;
	}

	cout << s << '\n';
	return 0;
}