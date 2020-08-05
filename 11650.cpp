#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// pair를 사용해서 비교함수를 만들어준다.
// const 와 & 꼭 붙여주기.
bool cmp(const pair<int, int>& u, const pair<int, int>& v) {
	if (u.first < v.first) {
		return true;
	}
	else if (u.first == v.first) {
		return u.second < v.second;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second; // pair를 사용하여 첫번 째 값, 두번 째 값 받아주기.
	}
	sort(a.begin(), a.end(), cmp); // sort 사용하여 정렬, 마지막에 함수의 이름 포함 시켜주기.

	for (int i = 0; i < n; i++) {
		cout << a[i].first << " " << a[i].second << "\n";
	}

	return 0;
}
