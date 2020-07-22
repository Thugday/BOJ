#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
	string name;
	int kr, eng, math;
}; //struct을 사용해 정보를 생성.

bool cmp(const Person& u, const Person& v) {
	if (u.kr > v.kr) {
		return true;
	}
	else if (u.kr == v.kr) {
		if (u.eng < v.eng) {
			return true;
		}
		else if (u.eng == v.eng) {
			if (u.math > v.math) {
				return true;
			}
			else if (u.math == v.math) {
				return u.name < v.name;
			}
		}
	}
	return false;
} // if문을 사용해 국, 영, 수, 이름 순서대로 비교

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	vector<Person> m(n);

	for (int i = 0; i < n; i++) {
		cin >> m[i].name >> m[i].kr >> m[i].eng >> m[i].math;
	}

	sort(m.begin(), m.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << m[i].name << "\n"; 
	}

	return 0;
}