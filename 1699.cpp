#include <iostream>
#include <algorithm>
#define MAX 100001 // 최대 자연수 100000.

using namespace std;

int d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		d[i] = i; // d[i]의 초기값은 1이 n번인 상태.
		for (int j = 1; j * j <= i; j++) { // j^2는 i보다 작거나 같아야 한다.
			if (d[i] > d[i - (j * j)] + 1) {
				d[i] = d[i - (j * j)] + 1; // min(d[n-i^2] + 1)
			}
		}
	}

	cout << d[n] << '\n';

	return 0;
}