#include <iostream>

using namespace std;

long long d[1001][10]; // d[n][l] = n자리 오르막수, 마지막 수는 l.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	long long m(0);

	for (int i = 0; i <= 9; i++) { // 길이가 1인 경우 0부터 9까지 가능.
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) { // d[n][l] 을 채워주는 for 문.
			for (int k = 0; k <= j; k++) { // d[k] 는 마지막자리 전 n-1의 자리를 채워주는 for 문.
				d[i][j] += d[i - 1][k];
				d[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++) { // 길이가 n이고 마지막 자리가 0부터 9가 될 수있는 오르막수.
		m += d[n][i];
	}

	m %= 10007;

	cout << m << '\n';

	return 0;
}