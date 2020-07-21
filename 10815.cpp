#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n1;
	cin >> n1;

	set<int> s;
	for (int i = 0; i < n1; i++) {
		int m;
		cin >> m;
		s.insert(m); // set에 인풋 넣어주기.
	}

	int n2;
	cin >> n2;

	for (int i = 0; i < n2; i++) {
		int m;
		cin >> m;
		cout << s.count(m) << ' '; // count로 set에 있는지 없는지 확인.
	}

	cout << "\n";

	return 0;
}