#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int a[MAX][MAX];
int d[MAX][MAX];

// 사탕을 얻을 수 있는 최대값을 구하기위한 함수.
int max_path(int x, int y, int z) {
	return max(x, max(y, z));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m; // 미로 크기 입력받기.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j]; // 사탕의 개수 입력 받기.
		}
	}

	// 미로를 오른쪽, 아래쪽, 대각선으로 돌아다니면서 얻을 수 있는 사탕의 최대값을 구할 수 있는 loop.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = max_path(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + a[i][j];
		}
	}

	cout << d[n][m] << '\n';
	return 0;
}