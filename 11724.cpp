#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
bool check[MAX];

void dfs(int x);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int comp(0);
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			comp += 1; // dfs가 시작할때마다 component를 증가시켜줌으로써, 연결요소가 몇 개인지 구할 수 있다.
		}
	}

	cout << comp << '\n';

	return 0;
}

void dfs(int x) { // dfs 구현.
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}
