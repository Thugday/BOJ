#include <iostream>
#include <queue>
#define MAX 1000010

using namespace std;

int F, S, G, U, D;
int v[MAX] = { 0, };
queue <int> q;

int bfs() {	
	q.push(S);
	v[S] = 1;
	while (!q.empty()) {
		int present = q.front();

		// 목표층에 도달시
		if (present == G) {
			return v[present] - 1;
		}
		q.pop();
		// 위로 U 층만큼, 아래로 D 층만큼 움직일 수 있다.
		int next[2] = { present + U, present - D };
		for (int i = 0; i < 2; i++) {
			// 범위안에 있으면서 방문하지 않은 층을 넣어준다. 
			if (1 <= next[i] && next[i] <= F) {
				if (v[next[i]] == 0) {
					v[next[i]] = v[present] + 1;
					q.push(next[i]);
				}
			}
		}
	}
	return -1; // 목표층에 도달하지 못할 시.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> F >> S >> G >> U >> D;
	int sol = bfs();
	if (sol == -1) {
		cout << "use the stairs\n";
	}
	else {
		cout << sol;
	}
	return 0;
}