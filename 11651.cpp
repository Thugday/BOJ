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
} // pair를 사용한 비교함수. y가 증가하는 순으로 비교를 먼저 해준다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << "\n";
	}

	return 0;
}