#include <iostream>
#include <algorithm>
#define MAX 305

int a[MAX];
int d[MAX];

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i]; // n까지의 수열 입력 받아주기.
	}
	
	d[1] = a[1]; // 예외처리, 계단 1개일땐 한 번 오르는 것이 최대 점수.
	d[2] = a[1] + a[2]; // 예외처리, 계단 2개일 땐 두 계단 한 번씩 오르는 것이 최대 점수.

	for (int i = 3; i <= n; i++) {
		d[i] = max(d[i - 2] + a[i], d[i - 3] + a[i] + a[i - 1]); // d[i-2] + a[i] 는 한 계단 씩 오를때, d[i-3] + a[i] + a[i-1] 은 두 계단씩 오를 때의 점화식.
	}

	cout << d[n] << '\n';

	return 0;
}