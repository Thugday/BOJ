#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int lottery[6];
int d[13];

// x는 d의 인덱스, y는 lottery의 인덱스.
void combinations(int x, int y) {

	// 6개의 인덱스가 모였으면 출력.
	if (y == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lottery[i] << " ";
		}
		cout << '\n';
		return;
	}

	// 재귀함수, 인풋해주기.
	for (int i = x; i < n; i++) {
		lottery[y] = d[i];
		combinations(i + 1, y + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		cin >> n;

		if (n == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		combinations(0, 0);
		cout << '\n';
	}
	return 0;
}