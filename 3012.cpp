#include <iostream>
#include <string>
#include <cstring>
#define MAX 210

using namespace std;

const long long mod = 100000;
string s;
long long d[MAX][MAX];
// 괄호를 구현해 준다.
char started[5] = "([{";
char ended[5] = ")]}";

long long solve(int i, int j) {
	if (i > j) {
		return 1;
	}

	long long& ans = d[i][j];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	
	// 짝이 맞아야 되기 때문에 k+=2로 두 칸 씩 이동해 준다.
	for (int k = i + 1; k <= j; k += 2) {
		for (int p = 0; p < 3; p++) {
			// 해당하는 닫는 괄호를 찾아준다.
			if (s[i] == started[p] || s[i] == '?') {
				if (s[k] == ended[p] || s[k] == '?') {
					// solve의 거리는 짝수가 되면 된다.
					long long temp = solve(i + 1, k - 1) * solve(k + 1, j);
					ans += temp;
					if (ans >= mod) {
						ans = mod + ans % mod;
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin >> s;

	memset(d, -1, sizeof(d));
	long long ans = solve(0, n - 1);

	// 5자리가 넘었을 때와 넘지 않았을 때 구현.
	if (ans >= mod) {
		printf("%05lld\n", ans % mod);
	}
	else {
		printf("%lld\n", ans);
	}

	return 0;
}