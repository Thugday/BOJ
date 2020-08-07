#include <iostream>

using namespace std;

bool c[1001];
int a[1001];

void dfs(int x) { // dfs 구현, 다음 정점이 1개이기 때문에 바로 dfs 해준다.
	if (c[x]) return;
	c[x] = true;
	dfs(a[x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	
	while (t--) { // 테스트 케이스
		int n;
		cin >> n; // 순열의 크기 입력.
		for (int i = 1; i <= n; i++) {
			cin >> a[i]; // 순열 입력.
			c[i] = false;
		}
		
		int x = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == false) {
				dfs(i);
				x += 1; // 순열 사이클이면 x에 1 추가.
			}
		}
		cout << x << '\n';
		
	}

	return 0;

}