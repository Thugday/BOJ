#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 500001

using namespace std;

int v[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // 사람의 수 입력 받기.

	for (int i = 0; i < n; i++) {
		cin >> v[i]; // 사람들의 키 입력받기.
	}

	stack<pair<int, int>> s; // 첫번 째 int : 키, 두번 째 int : 몇 명 연속인지.
	long long ans(0);

	for (int i = 0; i < n; i++) {
		pair<int, int> p = { v[i],1 };
		// 스택이 비어있지 않을 때.
		while (!s.empty()) {
			// 키의 스택이 다른 사람의 키보다 작을때.
			if (s.top().first <= v[i]) {
				ans += (long long)s.top().second; // 정답에 1 추가, 서로 마주볼 경우.
				if (s.top().first == v[i]) { // 키의 스택이 다른 사람의 키와 같을 때.
					p.second += s.top().second; // 스택에 키 큰 사람 넣어주기.
				}
				s.pop(); // 키가 큰 상대가 나타났으니 이전 스택은 pop 해준다.
			}
			else {
				break;
			}
		}
		if (!s.empty()) { // 키의 스택이 다른 사람의 키보다 클 때.
			ans += 1LL; // 마주보기 가능.
		}
		s.push(p); // 자기보다 키가 작은 사람이 나타났기 때문에 push.
	}
	cout << ans << '\n';
	return 0;
}