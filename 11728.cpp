#include <iostream>
#define MAX 1000000

using namespace std;

int a[MAX], b[MAX], c[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m; // 두 배열의 크기 입력 받기.

	for (int i = 0; i < n; i++) {
		cin >> a[i]; // a배열의 숫자 입력 받기.
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i]; // b배열의 숫자 입력받기.
	}

	int x(0), y(0), z(0);

	while (x < n && y < m) {
		if (a[x] <= b[y]) { // a배열이 b배열보다 작을경우 c 배열에 a배열의 수 추가.
			c[z++] = a[x++]; 
		}
		else {
			c[z++] = b[y++]; // b배열의 수가 더 작을 경우 c 배열에 b배열의 수 추가.
		}
	}

	// 왼쪽과 오른쪽 중 남아있는 수를 옮겨주기 위한 while 문.
	while (x < n) {
		c[z++] = a[x++];
	}
	while (y < m) {
		c[z++] = b[y++];
	}

	// 머지 소트를 완성한 배열을 출력해줌.
	for (int i = 0; i < n + m; i++) {
		cout << c[i] << ' ';
	}

	puts("");
	return 0;
}