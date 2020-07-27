#include <iostream>
#include <deque> // deque 헤더파일 추가
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	deque<int> d;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_front") { // deque의 push_front 구현
			int num;
			cin >> num;
			d.push_front(num);
		}
		else if (cmd == "push_back") { // deque의 push_back 구현
			int num;
			cin >> num;
			d.push_back(num);
		}
		else if (cmd == "pop_front") { // deque의 pop_front 구현
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n'; 
				d.pop_front();
			}
		}
		else if (cmd == "pop_back") { // deque의 pop_back 구현
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (cmd == "size") { // deque의 size 구현
			cout << d.size() << '\n';
		}
		else if (cmd == "empty") { // deque의 empty 구현
			cout << d.empty() << '\n';
		}
		else if (cmd == "front") { // deque의 front 구현
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
			}
		}
		else if (cmd == "back") { //deque의 back 구현
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
			}
		}
	}

	return 0;
}