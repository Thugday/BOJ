#include <iostream>
#define MAX 31

using namespace std;

long long a[MAX];
long long d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	a[1] = 1; // 대칭을 포함할 때.
	a[2] = 3;
	for (int i = 3; i <= 30; i++) {
		a[i] = a[i - 1] + a[i - 2] * 2LL;
	}

	d[1] = 1; // 대칭이 없을 때.
	d[2] = 3;

	for (int i = 3; i <= 30; i++) {
		long long b = 0;
		if (i % 2 == 1) {
			b = a[(i - 1) / 2]; // 홀수인 경우.
		}
		else {
			b = a[i / 2] + 2 * a[(i - 2) / 2]; // 짝수인 경우.
		}
		d[i] = (a[i] + b) / 2;
	}

	cout << d[n] << '\n';

	return 0;
}