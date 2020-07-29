#include <iostream>

using namespace std;

long long d[91]; // n의 최대는 90.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	d[1] = 1; // 예외처리. 한자리일 경우 1 으로 한 가지의 답.
	d[2] = 1; // 예외처리. 두자리일 경우 10 으로 한 가지의 답.

	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2]; // d[i-1] 은 마지막 자리에 0이 오는 경우, d[i-2]는 n번째 자리에 1이 오는 경우.
	}

	cout << d[n] << '\n';

	return 0;
}