#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

long long d[MAX];

int n, k;

bool check(long long x) {
	int cnt(0);
	for (int i = 0; i < n; i++) {
		cnt += d[i] / x; // x 길이로 잘라준다.
	}
	if (cnt >= k) { // k개 이상이면 true.
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	long long rhs(0);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		rhs = max(rhs, d[i]);
	}

	long long sol(0), lhs(1);
	while (lhs <= rhs) { // lhs 가 rhs 보다 작은동안 mid 는 (lhs + rhs) / 2.
		long long mid = (lhs + rhs) / 2;
		if (check(mid)) { // mid 변수를 check 함수에 넣어 몇개가 나오는지 확인.
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