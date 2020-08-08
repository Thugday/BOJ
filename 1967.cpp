#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 10001

using namespace std;

bool check[MAX];
int d[MAX];
vector<pair<int, int>> v[MAX]; // first는 정점, second는 weight.
queue<int> q;

int max1, max2;

void bfs(int c) {
	check[c] = 1;
	d[c] = 0;
	q.push(c);
	// 시작 부분 초기화.

	// bfs 구현.
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			if (check[v[x][i].first] == 0) {
				check[v[x][i].first] = 1;
				d[v[x][i].first] = v[x][i].second + d[x];
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

	int temp1(0), temp2(0), temp3(0);

	for (int i = 1; i < n; i++) {
		cin >> temp1 >> temp2 >> temp3;
		v[temp1].push_back(make_pair(temp2, temp3));
		v[temp2].push_back(make_pair(temp1, temp3));
	}
	

	bfs(1);

	memset(check, 0, sizeof(check));
	memset(d, 0, sizeof(d));
	max1 = 0;

	bfs(max2);

	cout << max1 << '\n';

	return 0;
}
