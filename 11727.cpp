#include <iostream>

using namespace std;

int d[1001]; // 최댓값 1000.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[0] = 1; // 최솟값을 0으로 시작해서 다이나믹프로그래밍 수식 형성.
	d[1] = 1;

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) { // Bottom-up 방식의 다이나믹프로그래밍.
		d[i] = d[i - 1] + (2 * d[i - 2]); // 2x2 수식은 2x1과 모양이 n-2로 같으므로 곱하기 2를 해준다.
		d[i] %= 10007; // 10007로 나눈 나머지의 값.
	}

	cout << d[n];

	return 0;
}