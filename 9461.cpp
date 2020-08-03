#include <iostream>
#include <algorithm>

using namespace std;

long long d[101] = { 0,1,1,1,2,2,3,4,5,7,9 }; // 초기값 설정.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 10; i <= 100; i++) {
		d[i] = d[i - 1] + d[i - 5]; // d[i] = d[i-1] + d[i-5]라는 규칙이 있으므로 점화식 사용.
	}

	int t;
	cin >> t;

	while (t--) { // 테스트 케이스
		int n;
		cin >> n;
		cout << d[n] << '\n';
	}

	return 0;
}