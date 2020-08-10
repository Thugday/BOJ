#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k; // 여학생, 남학생, 인턴 참가 학생 수 받기.

	int grp(0);

	while (n >= 2 && m >= 1 && m + n >= k+3) { // 여학생이 2명 이상, 남학생이 1명 이상, 합쳐진 학생수가 인턴수 + 3 보다 클 경우 대회 그룹에 더해주기.
		grp += 1;
		n -= 2;
		m -= 1;
	}

	cout << grp << '\n';

	return 0;
}