#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	int n = str.size();
	stack<int> s;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if (s.top() + 1 == i) { // 레이져 일때 스택의 크기 만큼 더해준다.
				s.pop();
				ans += s.size();
			}
			else {
				s.pop(); // 레이져가 아닐때는 쇠막대기이기 때문에 1을 더해준다.
				ans += 1; 
			}
		}
	}
	cout << ans << '\n';

	return 0;
}