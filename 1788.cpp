#include <iostream>
#define MAX 1000000000
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int result = 1; // n이 양수일 때, result 값은 변하지 않으므로 1로 초기화 시켜준다.
	
	long long a = 0, b = 1, c = 1;
	long long ans = 0;

	cin >> n;

	// n의 크기가 0보다 작을 때.
	if (n < 0) {
		if (n % 2 == 0) { // 짝수 일때는 음수가 나온다.
			result = -1;
		}
		n = -n; // -부호를 사용하여, 양수로 바꿔준다. (대칭인 점 이용)
	}

	// n이 0일 때 0출력.
	if (n == 0) {
		result = 0;
	}

	// n이 0또는 양수일 때.
	for (int i = 0; i < n; i++) {
		if (i == 0) { // 예외처리, 0일 때 0.
			ans = 0;
		} 
		if (i == 1) { // 예외처리, 1일 때 1.
			ans = 1;
		}
		else { 
			c = (a + b) % MAX;
			a = b;
			b = c;
			ans = c;
		}
	}

	cout << result << '\n';
	cout << ans;

	return 0;
}