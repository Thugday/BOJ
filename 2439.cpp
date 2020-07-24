#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j <= n - i) {
				cout << " "; // 공백을 끝에서 n - i자리 만큼 남기고 출력
			}
			else {
				cout << "*"; // 남은 n - i의 자리만 별 출력.
			}
		}
		cout << "\n";
	}

	return 0;
}