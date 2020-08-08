#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 100001

using namespace std;

int depth[MAX], d[MAX], parent[MAX];
bool check[MAX];
vector<int> a[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	queue<int> q;
	depth[1] = 0; // 루트 1.
	check[1] = true; // 1은 방문 한 상태.
	parent[1] = 0; // 1의 루트는 없으니 0.
	q.push(1);
	
	// bfs 구현.
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int y : a[x]) {
			if (!check[y]) {
				depth[y] = depth[x] + 1; // depth 1 증가.
				check[y] = true; // 방문 표시.
				parent[y] = x; // 다음 y 가 현재 x가 된다.
				q.push(y);
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}