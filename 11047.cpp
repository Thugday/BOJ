#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v(0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k; // 동전의 종류 수, 원하는 가치의 합 입력 받기.
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; // 동전의 종류 수 만큼 값의 크기 받아주기.
	}

	int sol(0);
	// 동전이 오름차순으로 입력 받아졌기 때문에, 뒤에서 부터 순회를 해주고 몇개를 만들고 나머지를 구해주면서 최소값을 구해준다.
	for (int i = n - 1; i >= 0; i--) {
		sol += k / v[i]; 
		k %= v[i];
	}

	cout << sol << '\n';
	return 0;
}