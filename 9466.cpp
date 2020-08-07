#include <iostream>

using namespace std;

int a[100001];
int d[100001]; // 정점 방문 여부를 저장.
int s[100001]; // 몇 번째 탐색에 의해 방문 된 것인지 저장.

int dfs(int x, int y, int& step) { // step은 어느 탐색에 해당되는지.
	while (true) {
		if (d[x] != 0) { // d[x]가 0이 아닐시 방문함.
			if (step != s[x]) {  // 이미 방문 했지만, 시작점이 다를 경우 cycle이 아니다.
				return 0;
			}
			return y - d[x];
		}
		d[x] = y;
		s[x] = step;
		x = a[x];
		y += 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	
	while (t--) { // 테스트 케이스.
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			d[i] = 0;
			s[i] = 0;
		}
		int temp = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0) {
				temp += dfs(i, 1, i);
			}
		}
		cout << n - temp << '\n';
	}

	return 0;
}

