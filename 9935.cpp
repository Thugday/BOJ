#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <algorithm>
#define MAX 1000010

using namespace std;

char a[MAX]; // 문자열.
bool check[MAX]; // 지워진 문자열이면 true, 아니면 false.
char b[100]; // 폭발 문자열.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a;
	cin >> b;

	int n = strlen(a);
	int m = strlen(b);

	// 폭발문자열의 길이가 1인 경우 첫번째 문자와 비교해서 지워짐. (예외처리)
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			if(a[i] == b[0])
			check[i] = true;
		}
	}
	else {
		stack<pair<int, int>> s;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[0]) { // 스택에 넣어주기.
				s.push(make_pair(i, 0));
			}
			else {
				if (!s.empty()) {
					auto p = s.top();
					if (a[i] == b[p.second + 1]) { // 스택에 제일 위에 있는거와 같으면 넣어주기.
						s.push(make_pair(i, p.second + 1));
						if (p.second + 1 == m - 1) { // 마지막 글자와 같으면 스택에서 pop 해주기
							for (int k = 0; k < m; k++) {
								auto p = s.top();
								check[p.first] = true;
								s.pop();
							}
						}
					}
					else {
						while (!s.empty()) { // 같지 않다면 스택을 모두 비워준다.
							s.pop();
						}
					}
				}
			}
		}
	}

	bool p_temp = false;

	for (int i = 0; i < n; i++) {
		if (check[i]) {
			continue;
		}
		cout << a[i];
		p_temp = true;
	}
	
	// 모든 문자열이 폭발하였을 때 "FRULA" 출력.
	if (!p_temp) {
		cout << "FRULA" << '\n';
	}
	
	return 0;
}