#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 10000

using namespace std;

bool check[MAX];
int d[MAX];
char meth[MAX];
int sp[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		memset(check, false, sizeof(check));
		memset(d, 0, sizeof(d));
		memset(meth, 0, sizeof(meth));
		memset(sp, 0, sizeof(sp));

		check[n] = true;
		d[n] = 0;
		sp[n] = -1;

		queue<int> q;
		q.push(n);

		while (!q.empty()) {
			int present = q.front();
			q.pop();

			// 'D' 연산 구현.
			int next = (present * 2) % 10000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				d[next] = d[present] + 1;
				sp[next] = present;
				meth[next] = 'D'; 
			}
			

			// 'S' 연산 구현.
			next = present - 1;
			if (next == -1) {
				next = 9999;
			}
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				d[next] = d[present] + 1;
				sp[next] = present;
				meth[next] = 'S';
			}
			
			// 'L' 연산 구현.
			next = (present % 1000) * 10 + present / 1000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				d[next] = d[present] + 1;
				sp[next] = present;
				meth[next] = 'L';
			}

			// 'R' 연산 구현.
			next = (present / 10) + (present % 10) * 1000;
			if (check[next] == false) {
				q.push(next);
				check[next] = true;
				d[next] = d[present] + 1;
				sp[next] = present;
				meth[next] = 'R';
			}
		}
		string sol = "";
		while (m != n) {
			sol += meth[m];
			m = sp[m];
		}

		reverse(sol.begin(), sol.end()); // 역순으로 만든 방법이 저장되어있기 때문에 reverse 사용.
		cout << sol << '\n';
	}
	return 0;
}