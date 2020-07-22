#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, a, b;

	cin >> n >> m;
	int* next = new int[n + 1];

	for (int i = 0; i <= n; i++) {
		next[i] = i;
	}
	while (m--) {
		cin >> a >> b;
		swap(next[a], next[b]);
	}
	
	for (int j = 1; j <= n; j++) {
		cout << next[j] << " ";
	}

	return 0;

}