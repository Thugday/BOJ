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
		d[i] = 1; // 모든 수 자체에 길이 1이 들어감.
		for (int j = 0; j < i; j++) { 
			if (d2[i] < d2[j] && d[i] < d[j] + 1) { // d2[i] < d2[j]를 사용하여, 감소하는 순으로 찾아준다.
				d[i] = d[j] + 1; // 길이 1 더해주기.
			}
		}
	}

	int ans(0);

	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]); // 감소 수열의 max값.
	}

	cout << ans << '\n';

	return 0;
}