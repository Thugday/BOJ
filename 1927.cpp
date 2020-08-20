#include <iostream>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	// priority_queue 가 최대힙을 구하는 성질이기 때문에, 안에 vector<int>와 greater<int>를 넣어주어 최소힙을 구해준다.
	priority_queue<int, vector<int>, greater<int>> q;

	cin >> n;
		
	while (n--) {
		int x;
		cin >> x;

		if (x == 0) {
			cout << (q.empty() ? 0 : q.top()) << '\n';
			if (!q.empty()) {
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
	return 0;
}