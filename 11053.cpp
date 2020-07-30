#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int d2[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> d2[i]; // 수열에 들어가는 값 입력 받기.
	}

	for (int i = 0; i < n; i++) {
		d[i] = 1; // 모든 수 자체에 1이 들어간다.
		for (int j = 0; j < i; j++) { // j 가 i보다 작아야 증가하는 수열이 됨.
			if (d2[j] < d2[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1; // 길이를 증가해주는 것이기 때문에 +1을 해준다.
			}
		}
	}

	int ans(0);

	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]); // d[i]의 max값.
	}

	cout << ans << '\n';

	return 0;
}