#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

// 왼쪽인지 오른쪽인지 어느 곳에 속하는지 모름.
struct Node {
	int val;
	Node* left;
	Node* right;
	Node() {
		val = 0;
		left = NULL;
		right = NULL;
	}
};

// 순서를 알기위한 preorder 재귀함수 구현.
string preorder(Node* root) {
	string ans = "";
	ans += "V"; // 방문했을 시.
	if (root->left) {
		ans += "L"; // 왼쪽 자식 방문 시.
		ans += preorder(root->left);
		ans += "l"; // 왼쪽 자식 방문이 끝날때.
	}
	if (root->right) {
		ans += "R"; // 오른쪽 자식 방문 시.
		ans += preorder(root->right);
		ans += "r"; // 오른쪽 자식 방문이 끝날 때.
	}
	ans += "v"; // 방문이 끝날 때.
	return ans;
}

// 트리를 지우기 위한 remove 재귀함수 구현.
void remove(Node* root) {
	if (root->left) {
		remove(root->left);
	}
	if (root->right) {
		remove(root->right);
	}
	delete root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	set<string> s;
	for (int i = 0; i < n; i++) {
		vector<int> v(m);
		for (int j = 0; j < m; j++) {
			cin >> v[j];
		}
		Node* root = new Node; // 루트 생성.
		root->val = v[0];
		for (int k = 1; k < m; k++) {
			Node* cur = root;
			while (true) {
				if (cur->val > v[k]) { // 현재 루트 값보다 작은 경우. (왼쪽에 있어야됨.)
					if (cur->left == NULL) { // 왼쪽 자식이 없을 경우.
						cur->left = new Node; // 왼쪽 자식에 삽입.
						cur->left->val = v[k];
						break;
					}
					else {
						cur = cur->left; // 왼쪽 자식이 있을 경우 탐색.
					}
				}
				else if (cur->val < v[k]) { // 현재 루트 값보다 큰 경우. (오른쪽에 있어야됨.)
					if (cur->right == NULL) { // 오른쪽 자식이 없을 경우.
						cur->right = new Node; // 오른쪽 자식에 삽입.
						cur->right->val = v[k];
						break;
					}
					else {
						cur = cur->right; // 오른쪽 자식이 있을 경우 탐색.
					}
				}
				else {
					break;
				}
			}
		}
		s.insert(preorder(root));
		remove(root);
	}
	cout << s.size() << '\n';
	return 0;
}