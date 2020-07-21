#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set<int> s;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x); //set에 값 저장.
	}

	for (auto a : s) {
		cout << a << ' '; //set의 값을 모두 출력.
	}

	cout << '\n';

	return 0;
}