#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long t(0), f(0);
	long long n, m;
	cin >> n >> m;

    // nCm = n! / (m!(n-m)!)
    // n, m, n-m에 따른 2의 갯수, 2의 제곱의 갯수 세주기
    for (long long i = 2; i <= n; i *= 2) {
        t += n / i;
    }
    for (long long i = 2; i <= n - m; i *= 2) {
        t -= (n - m) / i;
    }
    for (long long i = 2; i <= m; i *= 2) {
        t -= m / i;
    }

    // n, m, n-m에 따른 5의 갯수, 5의 제곱의 갯수 세주기
    for (long long i = 5; i <= n; i *= 5) {
        f += n / i;
    }
    for (long long i = 5; i <= n - m; i *= 5) {
        f -= (n - m) / i;
    }
    for (long long i = 5; i <= m; i *= 5) {
        f -= m / i;
    }

    // 2가 큰지 5가 큰지 모르니 최소값을 구해주면 조합 0의 갯수를 알수 있다.
    cout << min(t, f) << '\n';
    return 0;
}