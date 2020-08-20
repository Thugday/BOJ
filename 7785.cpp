#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	set<string> s; // 회사 사람의 이름을 넣기위한 set 생성.
	while (n--) {
		string name, work;
		cin >> name >> work;
		if (work == "enter") { // "enter"이면 set에 추가.
			s.insert(name);
		}
		else { // "enter"가 아니면 set에서 이름을 찾아 지워준다.
			s.erase(s.find(name));
		}
	}

	for (auto it = s.rbegin(); it != s.rend(); it++) { // 회사에 있는 사람을 역순으로 출력해야되기 때문에 rbegin과 rend를 쓴다.
		cout << *it << '\n';
	}

	return 0;

}