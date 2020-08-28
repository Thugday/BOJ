#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// 피보나치 수가 long long범위를 벗어나므로, string 사용.

string Add(string& s1, string& s2) {
	string result(max(s1.size(), s2.size()), '0');
	bool check = false;

	for (int i = 0; i < result.size(); i++) {
		int temp = check;
		check = false;

		if (i < s1.size()) {
			temp += s1[s1.size() - i - 1] - '0';
		}

		if (i < s2.size()) {
			temp += s2[s2.size() - i - 1] - '0';
		}

		if (temp >= 10) {
			check = true;
			temp -= 10;
		}

		result[result.size() - i - 1] = temp + '0';
	}

	if (check) {
		result.insert(result.begin(), '1');
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	string a = "0";
	string b = "1";

	if (n == 0) { // 예외처리 0일 때.
		cout << a << '\n';
	}
	else if (n == 1) { // 예외처리 1일 때.
		cout << b << '\n';
	}
	else if (n == 2) { // 예외처리 2일 때.
		cout << b << '\n';
	}
	else {
		string result;
		for (int i = 0; i <= n - 2; i++) {
			result = Add(a, b);
			a = b;
			b = result;
		}

		cout << result << '\n';
	}
	return 0;
}