#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[20][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // 도시의 수 입력 받기.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j]; // 비용 행렬 입력 받기.
		}
	}

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i;
	}

	int way = 2147483647; // int 최대값.

	// 순열을 사용한 그냥 다 해보기.
	do {
		bool check = true;
		int sum = 0;
		// a[0] 부터 a[n-1]까지 경로.
		for (int i = 0; i < n - 1; i++) {
			if (a[v[i]][v[i + 1]] == 0) { // w[i][j]가 0일때 예외처리, false 처리.
				check = false;
			}
			else {
				sum += a[v[i]][v[i + 1]];
			}
		}

		// 원래 도시로 돌아오는 코드.
		if (check && a[v[n - 1]][v[0]] != 0) {
			sum += a[v[n - 1]][v[0]];
			if (way > sum) {
				way = sum;
			}
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << way << '\n';
	return 0;
}