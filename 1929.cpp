#include <iostream>
#define MAX 1000000 // 최대 백만.

using namespace std;

bool check[MAX+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//에라토스테네스의 체 구현.
	check[0] = check[1] = true;

	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= MAX; j += i) {
				check[j] = true;
			}
		}
	}

	int a, b;
	cin >> a >> b;

	// a ~ b까지 있는 수 중 에라토스테네스의 체를 통해 소수를 찾아준다.
	for (int i = a; i <= b; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}

	return 0;
}