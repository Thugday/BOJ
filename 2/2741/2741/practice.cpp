#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, int>& u, const pair<int, int>& v) {
	if (u.second < v.second) {
		return true;
	}
	else if (u.second == v.second) {
		return u.first < v.first;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n(0);
	vector<pair<int, int>> a(n);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << "\n";
	}
}
