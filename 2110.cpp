#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 집 좌표 : v, 인접 공유기 사이의 거리 : x, c개 이상이면 true, 아니면 false.
bool check(vector<int> &v, int c, int x) {
	int cnt(1);
	int last = v[0];
	for (int apt : v) {
		if (apt - last >= x) {
			cnt += 1;
			last = apt;
		}
	}
	return cnt >= c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long c;
	cin >> n >> c;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int lhs = 1; // 제일 작은 값 1.
	int rhs = v[n - 1] - v[0]; // 가장 오른쪽에서 왼쪽 집까지의 차이.
	int sol = lhs;

	while (lhs <= rhs) {
		int mid = (lhs + rhs) / 2;
		if (check(v, c, mid)) {
			if (sol < mid) {
				sol = mid;
			}
			lhs = mid + 1;
		}
		else {
			rhs = mid - 1;
		}
	}

	cout << sol << '\n';
	return 0;
}