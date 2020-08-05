#include <iostream>
#include <algorithm>

using namespace std;

int m[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // 갯수 입력 받기.

	for (int i = 0; i < n; i++) {
		cin >> m[i]; // 갯수에 따른 수 입력 받기.
	}

	sort(m, m + n); // sort를 사용해서 정렬해준다.
	for (int i = 0; i < n; i++) {
		cout << m[i] << '\n'; // 차례대로 output 해주기.
	}

	return 0;
}