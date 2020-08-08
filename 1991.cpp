#include <iostream>
#include <algorithm>

using namespace std;

int a[50][2];

void preorder(int x){ // 프리오더 구현.
	if (x == -1) {
		return;
	}
	cout << (char)(x + 'A'); // 노드 먼저 출력.
	preorder(a[x][0]);
	preorder(a[x][1]);
}

void inorder(int x) { // 인오더 구현.
	if (x == -1) {
		return;
	}
	inorder(a[x][0]);
	cout << (char)(x + 'A'); // 노드 중간 출력.
	inorder(a[x][1]);
}

void postorder(int x) { // 포스트오더 구현.
	if (x == -1) {
		return;
	}
	postorder(a[x][0]);
	postorder(a[x][1]);
	cout << (char)(x + 'A'); // 노드 마지막에 출력.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z; // 알파벳 입력 받기.
		x = x - 'A';
		if (y == '.') { // 왼쪽 자식이 없는 경우 : -1.
			a[x][0] = -1;
		}
		else {
			a[x][0] = y - 'A';
		}
		if (z == '.') { // 오른쪽 자식이 없는 경우 : -1.
			a[x][1] = -1;
		}
		else {
			a[x][1] = z - 'A';
		}
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

	return 0;
}