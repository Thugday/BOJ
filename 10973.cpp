#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	// algorothm STL에 있는 prev_permutation을 사용한 이전 순열 구하기.
	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}

	cout << '\n';

	return 0;
}