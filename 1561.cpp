#include <iostream>

using namespace std;

int n, m;
int d[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> d[i];
	}

	if (n <= m) { // 예외 처리, 0분.
		cout << n << '\n';
		return 0;
	}

	long long lhs(0), rhs(2000000000LL * 1000000LL); // 왼쪽은 0 시작, 오른쪽은 n제한중 제일 큰 값.
	while (lhs <= rhs) {
		long long mid = (lhs + rhs) / 2;
		long long start, end;
		start = end = 0;
		end = m;
		for (int i = 0; i < m; i++) {
			end += mid / d[i]; // 각각의 주기를 나눠주고 더해준다.
		}
		start = end;
		for (int i = 0; i < m; i++) {
			if (mid % d[i] == 0) { 
				start -= 1; // 이 때 탄 학생의수를 위해 start를 빼준다.
			}
		}
		start += 1;
		// 이분탐색.
		if (n < start) {
			rhs = mid - 1;
		}
		else if (n > end) {
			lhs = mid + 1;
		}
		else {
			for (int i = 0; i < m; i++) {
				if (mid % d[i] == 0) { // 그 주기에 얼마나 타있는지 보기 위해 다시 %한것이 0인것을 구해준다.
					if (n == start) {
						cout << i + 1 << '\n';
						return 0;
					}
					start += 1;
				}
			}
		}
	}
	return 0;
}