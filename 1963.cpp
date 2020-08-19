#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#define MAX 10001

using namespace std;

bool primenum[MAX];
bool check[MAX];
int d[MAX];

int change(int n, int x, int y) {
	if (x == 0 && y == 0) { // 맨 앞 수가 0이면 불가능하다.
		return -1;
	}
	string s = to_string(n); // string 형태로 변환.
	s[x] = y + '0'; // x 번째를 바꿔준다. 
	return stoi(s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 에라토스테네스의 체를 써서 소수를 구해줌.
	for (int i = 2; i <= MAX-1; i++) {
		if (primenum[i] == false) {
			for (int j = i * i; j <= MAX-1; j += i) {
				primenum[j] = true;
			}
		}
	}
	for (int i = 0; i <= MAX-1; i++) {
		primenum[i] = !primenum[i];
	}

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		memset(check, false, sizeof(check));
		memset(d, 0, sizeof(d));
		d[n] = 0;
		check[n] = true;
		queue<int> q;
		q.push(n);

		while (!q.empty()) {
			int present = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(present, i, j); // i번째 자리 수를 j로 바꾼다.
					// 바꿀 수 있을 때.
					if (next != -1) {
						if (primenum[next] && check[next] == false) {
							q.push(next);
							d[next] = d[present] + 1;
							check[next] = true;
						}
					}
				}
			}
		}

		cout << d[m] << '\n';
	}
	return 0;	
}