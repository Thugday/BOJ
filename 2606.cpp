#include <iostream>
#define MAX 101

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

	int n;
	cin >> n;

	// 각각의 원소를 루트 처리.
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	int m;
	cin >> m;

	// 테스트 케이스.
	while (m--) {
		int x, y;
		cin >> x >> y;
		Union(x, y); // 테스트 케이스의 수만큼 컴퓨터의 쌍 연결해주기.
	}

	int virus = 0;
	// 2번 부터 n번까지 1번 컴퓨터와 연결되어있는지 확인한다. 연결되어 있다면 virus에 1을 추가.
	for (int i = 2; i <= n; i++) {
		if (Find(1) == Find(i)) {
			virus += 1;
		}
	}

	cout << virus << '\n';
	return 0;
}