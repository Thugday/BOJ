#include <iostream>

using namespace std;

int gcd(int a, int b) { // 재귀함수를 통한 유클리드 호제법, 최대공약수 구하기.
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) { // 테스트 케이스.
		int n;
		int t[101];
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> t[i]; // n개의 수 만큼 input 받기.
		}

		long long sum(0);

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) { // 두 개를 선택 i, j로 나눠줌, 
				sum += gcd(t[i], t[j]); // 모든 경우에 대해 누적하여 최대공약수의 합 구하기.
			}
		}
		cout << sum << '\n';
	}
	return 0;
}