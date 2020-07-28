#include <iostream>

using namespace std;

int d[1001]; // 최댓값 1000.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[0] = 1; // 최솟값을 0으로 놓고 다이나믹을 완성시킨다.
	d[1] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) { // Bottom-up 방식의 다이나믹 프로그래밍.
		d[i] = d[i - 1] + d[i - 2]; // 다이나믹 수식.
		d[i] %= 10007;
	}

	cout << d[n];

	return 0;
}