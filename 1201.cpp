#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k; // n, m, k 입력 받아주기.

	vector<int> v(n);
	
	if (n >= m + k - 1 && n <= m * k) {
		for (int i = 0; i < n; i++) {
			v[i] = i + 1; // 1부터 n까지의 수 넣어주기.
		}

		vector<int> a;
		a.push_back(0);
		a.push_back(k); // 적어도 한 그룹은 k 가 되야 되기때문에 일단 k 넣기.
		n -= k;
		m -= 1;

		int n1 = m == 0 ? 1 : n / m;
		int n2 = m == 0 ? 0 : n % m;

		// 그룹의 크기 결정해 주기.
		for (int i = 0; i < m; i++) {
			a.push_back(a.back() + n1 + (n2 > 0 ? 1 : 0));
			if (n2 > 0) {
				n2 -= 1;
			}
		}

		for (int i = 0; i < a.size() - 1; i++) {
			reverse(v.begin() + a[i], v.begin() + a[i + 1]); // 각 그룹을 뒤집어 준다.
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	else {
		cout << "-1\n";
	}
	return 0;
}