#include <iostream>

using namespace std;

// 1에서 n까지의 원판을 x에서 y로 이동시킨다. 
void solve(int n, int x, int y) {
	if (n == 0) {
		return;
	} // 이동 시킬 원판이 없을 시 종료.
	solve(n - 1, x, 6 - x - y); // z = 6-x-y. n-1개를 x에서 z로 옮긴다.
	cout << x << " " << y << '\n';
	solve(n - 1, 6 - x - y, y); // n-1개를 z에서 y로 옮긴다.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // 총 몇 번 움직였는지 출력 해준다. 2^n - 1번.
	solve(n, 1, 3);
	return 0;
}