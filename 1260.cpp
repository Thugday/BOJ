#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> // bfs 사용.
#include <cstring> // memset 사용.

#define MAX 1001

using namespace std;

vector<int> a[MAX];
bool check[MAX];
int n, m, start;
void dfs(int x);
void bfs(int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(start);
	cout << "\n";

	memset(check, false, sizeof(check));

	bfs(start);
	cout << "\n";

	return 0;

}

void dfs(int x) { // dfs 구현.
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

void bfs(int x) { // bfs 구현.
	queue<int> q;
	check[x] = true; 
	q.push(x);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << ' ';
		for (int i = 0; i < a[node].size(); i++) {
			int y = a[node][i];
			if (check[y] == false) {
				check[y] = true;
				q.push(y);
			}
		}
	}
}
