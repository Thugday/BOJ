#include <iostream>

using namespace std;

int d[201]; // 최대 정수 200.
long long mod = 1000000000; // 나누는 값 : mod.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	d[0] = 1; // 초기값.
	
	for (int i = 1; i <= k; i++) {
		for (int j = n; j >= 0; j--) { // for 문이 뒤에서 부터 돌아줘야 일차원으로 표현이 가능하다.
			for (int l = 1; l <= j; l++) {
				d[j] += d[j - l]; // d[j-1] 을 자신에 더해줌으로써 일차원 다이나믹으로 표현 가능.
				d[j] %= mod;
			}
		}
	}

	cout << d[n] << '\n';

	return 0;
}