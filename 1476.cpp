#include <iostream>

using namespace std;

// 그냥 다 해보기
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int E, S, M;
	cin >> E >> S >> M;

	int e(1), s(1), m(1);
	
	// 1부터 E, S, M 과 같아질 때 까지 loop.
	for (int i = 1;; i++) { 
		if (e == E && s == S && m == M) {
			cout << i << '\n';
			return 0;
		}
		e += 1;
		s += 1;
		m += 1;
		if (e == 16) {
			e = 1;
		}
		if (s == 29) {
			s = 1;
		}
		if (m == 20) {
			m = 1;
		}
	}
	return 0;
}