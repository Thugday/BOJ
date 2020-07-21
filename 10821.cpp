#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int count(0);
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') { //comma 갯수를 확인 해 주면 몇 개의 정수인지 확인할 수 있음.
			count++;
		}
	}
	cout << count + 1 << '\n'; // 숫자는 항상 comma 보다 하나가 많기 때문에 +1을 해줌.
	return 0;
}