#include <iostream>
#include <algorithm>

using namespace std;

int d[1000001];
int temp(0);

int calc(int n) {
	if (n == 1) { // 예외처리, 1일 때는 해줄 연산이 없음.
		return 0;
	}
	if (d[n] > 0) { // 0보다 큰 값의 연산이 필요함. (memorization)
		return d[n];
	}
	d[n] = calc(n - 1) + 1; // n-1인 경우.
	if (n % 2 == 0) { 
		temp = calc(n / 2) + 1; // n/2인 경우.
		if (d[n] > temp) {
			d[n] = temp;
		}
	}
	if (n % 3 == 0) {
		temp = calc(n / 3) + 1; // n/3인 경우.
		if (d[n] > temp) {
			d[n] = temp;
		}
	}
	return d[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	cout << calc(n) << '\n';

	return 0;
}