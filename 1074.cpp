#include <iostream>

using namespace std;

int power(int k) {
	return(1 << k);
}

int solve(int s, int x, int y) {
	if (s == 1) {
		return 2 * x + y; // s가 1인경우 0,1,2,3 이기 때문에 return 2x+y.
	}
	else { // 4등분 했을때
		if (x < power(s - 1)) {
			if (y < power(s - 1)) {
				return solve(s - 1, x, y); // 대각선 왼쪽 위.
			}
			else {
				return solve(s - 1, x, y - power(s - 1)) + power(2 * s - 2); // 대각선 오른쪽 위.
			}
		}
		else {
			if (y < power(s - 1)) {
				return solve(s-1,x-power(s-1),y) + power(2*s-2)*2; // 대각선 왼쪽 아래.
			}
			else {
				return solve(s - 1, x - power(s - 1), y - power(s - 1)) + power(2 * s - 2) * 3; // 대각선 오른쪽 아래.
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, r, c;
	while (cin >> n >> r >> c) {
		cout << solve(n, r, c) << '\n';
		break;
	}
	return 0;
}