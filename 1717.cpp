#include <iostream>
#define MAX 1000001

using namespace std;

int parent[MAX];


// Find 함수 구현.
int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

// Union 함수 구현.
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	// 각각의 원소가 root가 되게 한다.
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	// 테스트 케이스.
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 0) { // 0일 때는 Union 해주기.
			Union(y, z);
		}
		else { // 1일 때는 find 해주기.
			y = Find(y);
			z = Find(z);
			if (y == z) { // 같은 집합일 시 "YES".
				puts("YES");
			}
			else {
				puts("NO"); // 다르다면 "NO".
			}
		}
	}
}