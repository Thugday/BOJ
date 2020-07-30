#include <iostream>
#include <algorithm>

using namespace std;

int d[1001];
int d2[1001];
int d3[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> d[i]; // 수열에 들어가는 값 입력 받기.
	}

	for (int i = 1; i <= n; i++) {
		d2[i] = 1;
		for (int j = 0; j < i; j++) {
			if (d[j] < d[i] && d2[i] < d2[j] + 1) { // 증가하는 수열 구해주기.
				d2[i] = d2[j] + 1;
			}
		}
	}


	for (int i = n; i >= 1; i--) {
		d3[i] = 1;
		for (int j = n; j > i; j--) {
			if (d[i] > d[j] && d3[i] < d3[j] + 1) { // 감소하는 수열 구해주기.
				d3[i] = d3[j] + 1;
			}
		}
	}


	int ans(0);

	for (int i = 1; i <= n; i++) {
		ans = max(ans, d2[i] + d3[i] - 1); // 가장 큰 값이 중복 되기 때문에 -1을 해준다.
	}


	cout << ans << '\n';

	return 0;
}