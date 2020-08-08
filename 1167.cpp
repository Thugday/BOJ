#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 100010

using namespace std;

bool check[MAX]; // 방문 유무.
int d[MAX]; // 거리.
vector<pair<int, int>> v[MAX];
queue<int> q;

int max1, max2;

// bfs 구현.
void bfs(int c) {
	check[c] = 1;
	d[c] = 0;
	q.push(c);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (check[v[x][i].first] == 0) {
				check[v[x][i].first] = 1;
				d[v[x][i].first] = v[x][i].second + d[x]; // 거리를 구하는 코드.
				q.push(v[x][i].first);
				if (d[v[x][i].first] > max1) {
					max1 = d[v[x][i].first];
					max2 = v[x][i].first;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int r(0);
	int b = 0, temp_b;

	for (int i = 0; i < n; i++) {
		cin >> temp_b;
		while (1) {
			cin >> r;
			if (r == -1) {
				break;
			}
			cin >> b;
			v[temp_b].push_back(make_pair(r, b));
		}
	}

	bfs(1); // 1부터 시작.
	memset(check, 0, sizeof(check));
	memset(d, 0, sizeof(d));
	max1 = 0;

	bfs(max2); // 다시 거리 재주기.
	
	cout << max1 << '\n';

	return 0;
}
