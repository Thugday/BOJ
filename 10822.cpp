#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int count(0), sum(0);
	string s, ans;

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			sum += stoi(ans);
			ans = "";
		}
		else {
			ans += s[i];
		}
	}

	cout << sum + stoi(ans) << '\n';

	return 0;
}