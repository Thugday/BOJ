#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

long long a[100001];

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		// 각각의 막대를 스택에 넣어준다.
		stack<long long> s;
		long long sol = 0;
		for (int i = 0; i < n; i++) {
			int left = i;
			while (!s.empty() && a[s.top()] > a[i]) {
				long long h = a[s.top()];
				s.pop(); // stack의 높이가 크면 pop 해준다.
				long long w = i;
				if (!s.empty()) {
					w = (i - s.top() - 1);
				}
				// 넓이 계산.
				if (sol < h * w) {
					sol = h * w;
				}
			}
			s.push(i);
		}
		// 제일 오른쪽 끝의 막대에 관한 넓이를 마지막으로 구해준다.
		while (!s.empty()) {
			long long h = a[s.top()];
			s.pop();
			long long w = n;
			if (!s.empty()) {
				w = n - s.top() - 1;
			}
			if (sol < h * w) {
				sol = h * w;
			}
		}
		cout << sol << '\n';
	}
	return 0;
}