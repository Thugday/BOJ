#include <iostream>
#include <string>

using namespace std;

struct Queue {
	int data[10000];
	int begin, end;
	
	Queue() {
		begin = 0;
		end = 0;
	}

	void push(int num) { // Queue의 push 구현.
		data[end] = num;
		end += 1;
	}

	bool empty() { // Queue의 empty 구현.
		if (begin == end) {
			return true;
		}
		else {
			return false;
		}
	}

	int size() { // Queue의 size 구현.
		return end - begin;
	}

	int front() { // Queue의 front 구현.
		return data[begin];
	}

	int back() { // Queue의 back 구현.
		return data[end - 1];
	}

	int pop() { // Queue의 pop 구현.
		if (empty()) {
			return -1;
		}
		begin += 1;
		return data[begin - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	Queue q;

	while (t--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << q.empty() << '\n';
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}

	return 0;
}