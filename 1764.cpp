#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	set<string> s;
	int n, m;
	cin >> n >> m;

	while (n--) {
		string name;
		cin >> name;
		s.insert(name); // 듣도 못한 사람을 set에 넣어준다.
	}

	vector<string> v;

	while (m--) {
		string name;
		cin >> name;
		if (s.count(name)) { // 보도 못한 사람을 입력 받아 듣도 못한 사람의 집합에 들어있는지 확인한다.
			v.push_back(name);
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';

	for (auto& name : v) {
		cout << name << '\n';
	}
	return 0;
}