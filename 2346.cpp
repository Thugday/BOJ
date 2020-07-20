#include <iostream>
#include <list>

using namespace std;

int main() {
	int n;
	list <pair<int, int>> l; //풍선의 번호와 수를 pair 형태로 저장
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		l.push_back({ a, i });
	}

	auto it = l.begin(); // 어떤 풍선인지 저장. 
	for (int i = 0; i < n - 1; i++) {
		cout << (*it).second << ' ';
		int next = (*it).first;
		if (next > 0) { // 양수일 땐 증가.
			auto temp = it;
			++temp;
			if (temp == l.end()) {
				temp = l.begin();
			}
			l.erase(it);
			it = temp;
			for (int i = 1; i < next; i++) {
				++it;  
				if (it == l.end()) {
					it = l.begin();
				}
			}
		}
		else if (next < 0) { // 음수일 때 erase. 
			next = -next;
			auto temp = it;
			if (temp == l.begin()) {
				temp = l.end();
			}
			--temp;
			l.erase(it);
			it = temp;
			for (int i = 1; i < next; i++) {
				if (it == l.begin()) {
					it = l.end();
				}
				--it;
			}
		}
	}
	cout << l.front().second << '\n';

	return 0;
}