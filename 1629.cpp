#include <iostream>

using namespace std;


// 분할정복 이용.
long long calc(long long a, long long b, long long c) {
	if (b == 0) { // 0번 곱하면 1.
		return 1LL;
	}
	else if (b == 1) { // 1번 곱하면 a는 똑같기 때문에 a % c.
		return a % c; 
	}
	else if (b % 2 == 0) { // 짝수번 곱할 경우.
		long long temp = calc(a, b / 2, c); // temp를 꼭 사용해야 된다. 사용하지 않으면 똑같은 것을 곱하게 된다.
		return (temp * temp) % c;
	}
	else { // 홀수번 곱할 경우.
		return (a * calc(a, b - 1, c)) % c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a, b, c;
	cin >> a >> b >> c;

	cout << calc(a, b, c) << '\n';

	return 0;
}