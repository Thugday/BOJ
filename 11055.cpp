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
		d[i] = d2[i]; // 합을 구하는 수열이기 때문에 수열의 값을 넣어준다.
		for (int j = 0; j < i; j++) { // j가 i보다 작아야 증가하는 수열이 된다.
			if (d2[j] < d2[i] && d[i] < d[j]+d2[i]) { // 길이인 1대신 합을 구해야하기 때문에 d2[i]값을 더해준다.
				d[i] = d[j] + d2[i];
			}
		}
	}

	int ans(0);

	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]); // d[i]의 합의 최대값.
	}

	cout << ans << '\n';

	return 0;
}