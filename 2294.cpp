#include <iostream>

using namespace std;

int a[101];
int d[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k; // 동전의 수, 가치의 합 입력 받기.

	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // 동전의 가치 입력 받기.
	}

	// 불가능한 경우. (최대일 때)
	for (int i = 0; i <= k; i++) {
		d[i] = 10001;
	}

	d[0] = 0; // 0일때는 최소 0.

	// 동전의 갯수만큼 반복, 가치의 합에서 특정 동전의 가치를 누적.
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) {
			d[j] = min(d[j], d[j - a[i]] + 1); // 최소값 출력.
		}
	}

	if (d[k] == 10001) cout << "-1" << '\n';
	else
	cout << d[k] << '\n';
	return 0;
}