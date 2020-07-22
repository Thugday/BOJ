#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string u, string v) {
	if (u.length() == v.length()) {
		return u < v;
	}
	else {
		return u.length() < v.length();
	}
} // 길이를 비교하는 비교함수.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	vector<string> m;
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (find(m.begin(), m.end(), s) == m.end()) {
			m.push_back(s);
		}
	}
	sort(m.begin(), m.end(), cmp);

	for (int i = 0; i < m.size(); i++) {
		cout << m[i] << '\n';
	}

	return 0;
}