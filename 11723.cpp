#include <iostream>
#include <cstring>

using namespace std;

char c[111];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 20;
	int m;
	cin >> m;

	int num(0);
	int x;

	while (m--) {
		cin >> c;
		if (!strcmp(c, "add")) {
			cin >> x;
			x--;
			num = (num | (1 << x)); // 비트연산자를 통해 집합에 추가시켜주기.
		}
		else if (!strcmp(c, "remove")) {
			cin >> x;
			x--;
			num = (num & ~(1 << x)); // 비트연산자를 통해 집합에서 제거시켜주기.
		}
		else if (!strcmp(c, "check")) {
			cin >> x;
			x--;
			int res = (num & (1 << x));
			if (res) {
				puts("1"); // 1 << x 가 있으면 1.
			}
			else {
				puts("0"); // 없다면 0.
			}
		}
		else if (!strcmp(c, "toggle")) {
			cin >> x;
			x--;
			num = (num ^ (1 << x)); // XOR 연산 사용.
		}
		else if (!strcmp(c, "all")) {
			num = (1 << n) - 1; // 2^n -1.
		}
		else if (!strcmp(c, "empty")) {
			num = 0;
		}
	}
	return 0;
}