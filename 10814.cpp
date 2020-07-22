#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person {
	int age;
	string name;
}; // 인물의 나이 이름 생성.

bool cmp(const Person &u, const Person &v) {
	if (u.age < v.age) {
		return true;
	}
	else {
		return false;
	}
} // 나이 비교를 위한 비교함수.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	vector<Person> m(n);

	for (int i = 0; i < n; i++) {
		cin >> m[i].age >> m[i].name;
	}

	stable_sort(m.begin(), m.end(), cmp); //stable_sort를 사용함으로써 원 상태 유지 하면서 비교

	for (int i = 0; i < n; i++) {
		cout << m[i].age << ' ' << m[i].name << "\n";
	}

	return 0;
}