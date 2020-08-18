#include <iostream>
#include <queue>
#define MAX 200001 // 돌아오는 경우 포함 10만에 두배인 20만.

using namespace std;

bool check[MAX];
int dist[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	check[n] = true;
	dist[n] = 0;
	
	// 시작지점 queue에 넣어주기.
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		// pop해주기.
		int now = q.front();
		q.pop();

		// x-1 일 때 다음 경로 push.
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}

		// x+1 일 때 다음 경로 push.
		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		
		// x*2 일 때 다음 경로 push.
		if (now * 2 < MAX) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}

	cout << dist[k] << '\n';
	return 0;
}