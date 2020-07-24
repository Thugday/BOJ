#include <iostream>
#include <stack>
#include <string>

using namespace std;

string valid(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') { // 여는 괄호 시 cnt에 1 추가.
			cnt += 1;
		}
		else {
			cnt -= 1; // 닫는 괄호 시 cnt에 -1 추가.
		}
		if (cnt < 0) {
			return "NO"; // 닫는 괄호가 먼저 나오면 순간적으로 -1이 먼저 나오기 때문에 NO 출력.
		}
	}
	if (cnt == 0) {
		return "YES"; // 합계 가 0이라면 정당한 괄호이므로 YES 출력.
	}
	else {
		return "NO"; // 아닐 시 NO 출력.
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		cout << valid(s) << '\n';
	}
	return 0;
}