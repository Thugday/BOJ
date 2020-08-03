#include <iostream>
#include <string>

#define MAX 5001 // 최대 5000자리 암호.

using namespace std;

int d[MAX];
int mod = 1000000; // 나눌 값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();

	s = " " + s;

	d[0] = 1; // 예외처리, 길이가 0이면 방법 1.
	for (int i = 1; i <= n; i++) {
		int a = s[i] - '0';
		if (1 <= a && a <= 9) { // 한 자리 암호로 해석하는 방법.
			d[i] += d[i - 1];
			d[i] %= mod;
		} 
		if (i == 1) { // 한 자리 수이기 때문에 길이가 2인 암호는 불가능.
			continue; 
		}
		if (s[i - 1] == '0') { // 앞자리가 0이면 불가능 하기 때문에 이것도 continue.
			continue;
		}
		a = (s[i - 1] - '0') * 10 + (s[i] - '0'); // 정수 a = 두 자리의 수.
		if (10 <= a && a <= 26) { // 알파벳의 갯수 26개.
			d[i] += d[i - 2];
			d[i] %= mod;
		}
	}

	cout << d[n] << '\n';

	return 0;
}