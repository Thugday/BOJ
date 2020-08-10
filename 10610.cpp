#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s; // string으로 수를 입력 받기.

	int sum(0);

	// 0을 뺀 합을 구해준다.
	for (char c : s) { 
		sum += c - '0';
	}

	sort(s.begin(), s.end()); // 오름차순으로 정렬 해주기.

	if (s[0] == '0' && sum % 3 == 0) { // 오름차순 정렬 후 첫번째 수가 0이고 3의 배수로 떨어지는지 구해준다. 
		reverse(s.begin(), s.end()); // 떨어진다면 내림차순으로 변경을해줘야 30배수 중 최대값이 된다.
		cout << s << '\n';
	}
	else {
		cout << "-1\n"; // 만약 오름차순 정렬 후 첫번째 수가 0이 아니거나 3의 배수로 떨어지지 않는 경우 -1 을 출력해준다.
	}

	return 0;
}