#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#define MAX 30000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<char> dq_front;
	deque<char> dq_back;

	string a, t;
	cin >> a >> t;

	int front = 0;
	int last = t.size() - 1;

	while (front <= last) {
		// 처음 등장하는 단어 A를 찾아 삭제해주기.
		while (front <= last) {
			bool b = false;
			dq_front.push_back(t[front]);
			front++;
			if (dq_front.size() >= a.size()) {
				b = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != dq_front[dq_front.size() - a.size() + i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				for (int i = 0; i < a.size(); i++) {
					dq_front.pop_back();
				}
				break;
			}
		}

		// 마지막으로 등장하는 단어 A를 찾은 뒤 삭제해주기.
		while (front <= last) {
			dq_back.push_front(t[last]);
			last--;
			bool b = false;
			if (dq_back.size() >= a.size()) {
				b = true;
				for (int i = 0; i < a.size(); i++) {
					if (a[i] != dq_back[i]) {
						b = false;
						break;
					}
				}
			}
			if (b) {
				for (int i = 0; i < a.size(); i++) {
					dq_back.pop_front();
				}
				break;
			}
		}
	}

	string solution;
	
	for (int i = 0; i < dq_front.size(); i++) {
		solution.push_back(dq_front[i]);
	}

	for (int i = 0; i < dq_back.size(); i++) {
		solution.push_back(dq_back[i]);
	}

	// 합쳐줬을때 단어 A가 나오면 삭제해주기.
	while (solution.find(a) < MAX) {
		solution.erase(solution.find(a), a.size());
	}

	if (!solution.empty()) {
		cout << solution << '\n';
	}

	return 0;
}