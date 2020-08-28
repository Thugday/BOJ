#include <iostream>
#define MAX 1500000

using namespace std;

// m : 10^6, 주기: 15 * 10^k-1, 즉 150만이 된다.
long long d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[0] = 0;
	d[1] = 1;

	// 10^18까지 구할 필요 x, 150만까지만 구해준다.
	for (int i = 2; i < MAX; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 1000000; // %m을 해준다.
	}

	long long n;
	cin >> n;
	cout << d[n % MAX] << '\n';

	return 0;
}