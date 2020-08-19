#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n(3), sp(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) {
				temp = 9;
			}
			sp = sp * 10 + temp;
		}
	}

	// 시작지점 map에 넣어주기.
	queue<int> q;
	q.push(sp);
	map<int, int> m;
	m[sp] = 0;

	while (!q.empty()) {
		// pop
		int present = q.front();
		string now = to_string(present);
		q.pop();
		int z = now.find('9'); // 0의 위치를 찾아준다.
		int x = z / 3;
		int y = z % 3;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				string next = now;
				swap(next[x * 3 + y], next[nx * 3 + ny]); // 2차원 배열을 1차원으로 나타냄에 따른 swap 식.
				int temp_num = stoi(next);
				if (m.count(temp_num) == 0) {
					m[temp_num] = m[present] + 1;
					q.push(temp_num);
				}
			}
		}
	}
	if (m.count(123456789) == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << m[123456789] << '\n';
	}
	return 0;
}