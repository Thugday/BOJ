#include <iostream>

using namespace std;

bool c[1000001];
long long min_value, max_value;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> min_value >> max_value; // min 값 max 값 입력 받기.

	// 에라토스테네스의 체 사용.
	for (long long i = 2; i*i <= max_value; i++) {
		long long x = i * i - min_value % (i * i);
		if (x == i * i) {
			x = 0;
		}
		for (long long j = x; j <= max_value - min_value; j += i * i) {
			c[j] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i <= max_value - min_value; i++) {
		if (c[i] == 0) {
			ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}