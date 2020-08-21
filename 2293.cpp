#include <iostream>

using namespace std;

int a[101];
int d[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k; // 동전의 수, 합한 수 입력 받기.

	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // 동전 가치 입력받기.
	}

	d[0] = 1; // 동전을 사용하지 않음. 1.

	// 동전의 갯수만큼 반복, 가치의 합에서 특정 동전의 가치를 누적.
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - a[i] >= 0) {
				d[j] += d[j - a[i]];
			}
		}
	}
	cout << d[k] << '\n';
	return 0;
}