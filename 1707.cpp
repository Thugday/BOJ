#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define MAX 20001

using namespace std;

vector<int> a[MAX];
int check[MAX];

bool bipartite(int x, int y) { // 이분그래프인지 확인해준다.
	check[x] = y;
	for (int i = 0; i < a[x].size(); i++) {
		int nxt = a[x][i];
		if (check[nxt] == 0) { // 아직 방문 하지 않았을 때.
			if (bipartite(nxt, 3 - y) == false) { // 다음 정점을 방문하지 않았을 때.
				return false;
			}
		}
		else if (check[nxt] == check[x]) { // 방문한 점일 경우 현재 정점과 다음 정점의 색이 같으면 false.
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			a[i].clear();
			check[i] = 0;
		}

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}

		bool ans = true;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				if (bipartite(i, 1) == false) {
					ans = false;
				}
			}
		}
		// 다음 정점과 이전 정점의 색이 같으면 false, 다르면 true.
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}