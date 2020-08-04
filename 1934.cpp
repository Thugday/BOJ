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

	while (t--) { // 테스트 케이스
		int a, b;
		cin >> a >> b;

		int g = gcd(a, b);
		int lcm = a * b / g; // L * G = A * B 성질을 이용한 최소공배수 구하기.
		
		cout << lcm << '\n'; // 최소공배수 출력해주기.
	}

	return 0;
}