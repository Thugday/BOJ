#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) { // 공백 부터 출력 해줘서 대칭 만들기
			cout << " "; 
		}
		for (int j = 0; j < 2 * i + 1; j++) { // 2*n+1 찍어주기.
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}