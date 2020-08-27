#include <iostream>

using namespace std;

int arr[101][101];
int arr2[101][101];
int farr[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int x, y;
	cin >> x >> y; // 첫 번째 행렬 크기 입력 받기.

	// 첫 번째 행렬 입력 받기.
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> arr[i][j];
		}
	}

	int z;
	cin >> y >> z; // 두 번째 행렬 크기 입력 받기.


	// 두 번째 행렬 입력 받기.
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < z; j++) {
			cin >> arr2[i][j];
		}
	}

	// 두 행렬 곱해주기.
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < z; j++) {
			for (int k = 0; k < y; k++) {
				farr[i][j] += arr[i][k] * arr2[k][j];
			}
		}
	}

	// 곱한 행렬 출력.
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < z; j++) {
			cout << farr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}