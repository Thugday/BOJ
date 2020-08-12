#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 나무의 길이 v, 자르려고 하는 나무의 높이 mid, m 보다 큰지 작은지 비교.
bool check(vector<long long> &v, long long mid, long long m ) {
    int n = v.size();
    long long cnt(0);
    for (int i = 0; i < n; i++) {
        if (v[i] - mid > 0) {
            cnt += v[i] - mid;
        }
    }
    return cnt >= m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    long long m;
	cin >> n >> m;

	vector<long long> v(n);
    long long lhs(0), rhs(0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
        if (rhs < v[i]) {
            rhs = v[i];
        }
	}
    // 이분 탐색 사용.
    long long sol(0);
    while (lhs <= rhs) {
        long long mid = (lhs + rhs) / 2;
        if (check(v, mid, m)) {
            sol = max(sol, mid);
                lhs = mid + 1;
        }
        else {
            rhs = mid - 1;
        }
    }
    cout << sol << '\n';
    return 0;
}
