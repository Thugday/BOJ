#include <iostream>
#include <map>

using namespace std;

// map을 사용하여 dynamic programming 
map<long long, long long> d;
const long long mod = 1000000007LL; // 나눠주는 수.

// 분할 정복 사용.
long long fibonacci(long long n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else if (d.count(n) > 0) {
		return d[n];
	}
	else { // 홀수일 때.
		if (n % 2 == 1) {
			long long m = (n + 1) / 2;
			long long temp = fibonacci(m);
			long long temp2 = fibonacci(m - 1);
			d[n] = temp * temp + temp2 * temp2;
			d[n] %= mod;
			return d[n];
		}
		else { // 짝수일 때.
			long long m = n / 2;
			long long temp = fibonacci(m - 1);
			long long temp2 = fibonacci(m);
			d[n] = (2LL * temp + temp2) * temp2;
			d[n] %= mod;
			return d[n];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;
	
	cout << fibonacci(n) << '\n';
	return 0;
}