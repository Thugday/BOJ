#include <iostream>
#include <algorithm>
#define MAX 31

using namespace std;

int d[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	 
	d[0] = 1; // 예외처리, 0일 경우에도 방법은 1.
	for (int i = 2; i <= n; i += 2) {
		d[i] = 3 * d[i - 2]; // n = 2일 때 방법이 세가지 이므로 *3.
		for (int j = i - 4; j >= 0; j -= 2) { // 길이가 늘어날때마다 짝수로 늘어남으로 i-4에서 0이 될때 까지 loop.
			d[i] += 2 * d[j]; // 2씩 늘어날때마다 2가지 경우가 계속 추가됨으로 *2.
		}
	}

	cout << d[n] << '\n';

	return 0;


}