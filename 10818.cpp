#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<int> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i]; // 주어진 정수 input 해주기.
	}

	auto it1 = min_element(a.begin(), a.end()); // 최솟값 찾아주기.
	cout << *it1 << ' '; 
	auto it2 = max_element(a.begin(), a.end()); // 최댓값 찾아주기.
	cout << *it2;

	return 0;
}