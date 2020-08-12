#include <iostream>

using namespace std;

int inorder[100010];
int postorder[100010];
int preorder[100010];

// 인오더, 포스트오더의 시작점과 끝점을 사용한 solve 함수. 포스트오더의 끝점은 루트이다.
void solve(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) { // 시작점이 끝점보다 작거나 같지 않으면 return.
		return;
	}
	int root = postorder[post_end];
	cout << root << ' ';
	
	int p = preorder[root];
	int lhs = p - in_start;
	
	solve(in_start, p - 1, post_start, post_start + lhs - 1); // 왼쪽 트리 찾기.
	solve(p + 1, in_end, post_start + lhs, post_end - 1); // 오른쪽 트리 찾기.
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	
	for (int i = 0; i < n; i++) {
		preorder[inorder[i]] = i;
	}

	solve(0, n - 1, 0, n - 1);

	return 0;
}