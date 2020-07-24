#include <iostream>
#include <string>
#include <stack>
#define MAX 10001

using namespace std;

struct Stack {
	int data[MAX];
	int size;

	Stack() { 
		size = NULL; // stack 의 size 구현.
	}

	void push(int x) { // stack의 push 구현.
		data[size] = x;
		size += 1;
	}

	bool empty() { // stack의 empty 구현.
		if (size == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	int pop() { // stack의 pop 구현.
		if (empty()) {
			return -1;
		}
		else {
			size -= 1;
			return data[size];
		}
	}

	int top() { // stack의 top 구현.
		if (empty()) {
			return -1;
		}
		else {
			return data[size - 1];
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	Stack s;
	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int num;
			cin >> num;
			s.push(num);
		}
		else if (cmd == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		}
		else if (cmd == "pop") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
			if (!s.empty()) {
				s.pop();
			}
		}
		else if(cmd == "empty"){
			cout << s.empty() << '\n';
		}
		else if (cmd == "size") {
			cout << s.size << '\n';
		}
	}

	return 0;
}