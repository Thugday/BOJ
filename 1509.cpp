#include <iostream>
#include <string>
#define MAX 2501

using namespace std;

int a[MAX];
int d[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s; // 문자열 입력받기.

	int n = s.size();
	s = " " + s;

	for (int i = 1; i <= n; i++) {
		d[i][i] = true; //  길이가 1일 때 true.
	}

	for (int i = 1; i <= n - 1; i++) {
		if (s[i] == s[i + 1]) {
			d[i][i + 1] = true; // 길이가 2일 때 true.
		}
	}

	// 길이가 3 이상일 때.
	for (int j = 2; j < n; j++) {
		for (int k = 1; k <= n - j; k++) {
			int x = j + k;
			d[k][x] = (s[k] == s[x] && d[k + 1][x - 1]);
		}
	}

	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = -1;
		for (int j = 1; j <= i; j++) {
			if (d[j][i]){
				if (a[i] == -1 || a[i] > a[j - 1] + 1) { // 최소값을 찾아줌.
					a[i] = a[j - 1] + 1; // 정답에 1을 더해준다.
				}
			} 
		}
	}
	cout << a[n] << '\n';
	return 0;

}