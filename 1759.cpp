#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 자음과 모음의 갯수를 체크하는 check 함수.
bool check(string& pw) {
	int cons(0), coll(0);
	for (char x : pw) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			coll += 1;
		}
		else {
			cons += 1;
		}
	}
	return cons >= 2 && coll >= 1;
}

// 재귀함수 구현.
void solve(int n, vector<char>& alpha, string pw, int i) {
	// 정답을 찾은 경우, n과 비밀번호의 길이가 같으면 된다.
	if (pw.length() == n) {
		if (check(pw)) {
			cout << pw << '\n';
		}
		return;
	}
	// 불가능한 경우.
	if (i >= alpha.size()) {
		return;
	}
	// 다음 경우.
	solve(n, alpha, pw + alpha[i], i + 1);
	solve(n, alpha, pw, i + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int L, C;
	cin >> L >> C;

	vector<char> v(C);
	for (int i = 0; i < C; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	solve(L, v, "", 0);

	return 0;
}