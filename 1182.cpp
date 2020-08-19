#include <iostream>

using namespace std;

int d[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	
	int sol = 0;
	
	// 공집합은 안 되니 1부터 2^n-1 까지 돌려준다.
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		// j가 들어있는지 확인해주고 들어있다면 j를 넣어준다.
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += d[j];
			}
		}
		// 같은 경우가 있을 시 정답에 1을 더해준다.
		if (sum == s) {
			sol += 1;
		}
	}

	cout << sol << '\n';
	return 0;
}