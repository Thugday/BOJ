#include <iostream>

using namespace std;

int a[101][101], b[101][101], n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m; //행렬의 크기 입력 받기.

	// 첫번째 행렬 입력 받기.
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	// 두번째 행렬 입력 받기.
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> b[i][j];

	// 두 행렬 더해주기.
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << a[i][j] + b[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
