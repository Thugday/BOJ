#include <iostream>

using namespace std;

int d[101][11]; // 100보다 작거나 같은 자연수. d[n][l] = n자리 계단수 마지막 수는 l.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1; // 길이가 1인 경우 존재 할 수 있는 case.
	}

	for (int i = 2; i <= n; i++) { // 길이가 2부터 n까지 인 경우.
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) { // 0보다 작을 경우 문제 발생, 0보다 큰 지 확인해줘야됨.
				d[i][j] += d[i - 1][j - 1];
			}
			if (j + 1 <= 9) { // 10이 올 수 없으므로, 9보다 작은 지 확인해줘야됨.
				d[i][j] += d[i - 1][j + 1];
			}
			d[i][j] %= 1000000000;
		}
	}

	long long m(0);

	for (int i = 0; i <= 9; i++) {
		m += d[n][i]; // 길이가 n이면서 마지막자리가 0부터 9까지 올 수있는 정답.
	}

	m %= 1000000000;
	
	cout << m << '\n';

	return 0;

}