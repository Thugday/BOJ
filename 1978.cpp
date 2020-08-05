#include <iostream>

using namespace std;

bool is_Prime(int x) { // 소수 찾기.
	if (x < 2) { // 0, 1 은 false 리턴.
		return false;
	}
	for (int i = 2; i * i <= x; i++) { // 2보다 크거나 같고, 루트 x보다 작거나 같은 수로 나눠 떨어지면 false 리턴. O(root_N)
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t; // 갯수 입력 받기.
	int n;
	int cnt(0);

	for (int i = 0; i < t; i++) {
		cin >> n; // 갯수에 따른 숫자 입력 받기.
		if (is_Prime(n)) { // 소수 찾기.
			cnt += 1; // 찾으면 cnt 1씩 증가.
		}
	}
	cout << cnt << '\n';
	return 0;
}