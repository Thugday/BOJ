#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> v[10001];
bool c[10001];
int n, m;
int island1, island2;

bool check(int node, int limit) {
	if (c[node]) {
		return false;
	}
	c[node] = true;
	if (node == island2) {
		return true;
	}
	for (auto &p : v[node]) {
		int next = p.first;
		int cost = p.second;
		if (cost >= limit) {
			if (check(next, limit)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	cin >> island1 >> island2;
	int lhs(1), rhs(1000000000);
	int sol(0);
	while (lhs <= rhs) {
		int mid = lhs + (rhs - lhs) / 2;
		memset(c, false, sizeof(c));
		if (check(island1, mid)) {
			sol = mid;
			lhs = mid + 1;
		}
		else {
			rhs = mid - 1;
		}
	}

	cout << sol << '\n';
	return 0;
}