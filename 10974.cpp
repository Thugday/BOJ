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
		v[i] = i + 1;
	}

	// do while 을 사용하여 모든 순열을 구해준다.
	do {
		for (int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}