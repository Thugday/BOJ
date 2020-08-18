#include <iostream>

using namespace std;

bool mess[10]; // 부셔진 버튼 true, 아니면 false.

// 채널이 0이면 0또는 1, 아니면 길이를 return.
int way(int c) {
	if (c == 0) { // 채널이 0일때의 예외 처리.
		if (mess[0]) {
			return 0;
		}else{
			return 1;
		}
	}

	int len = 0;

	// 버튼의 이상유무 확인해주기.
	while (c > 0) {
		if (mess[c % 10]) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		mess[x] = true;
	}

	int ans = N - 100; // N이 100 이상.
	if (ans < 0) {
		ans = -ans; // N이 100 이하
	}
	// 숫자 입력으로 이동할 채널 정해주기.
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = way(c); // 길이 재주기.
		if (len > 0) {
			int press = c - N; // +, - 버튼을 몇 번 눌러야되는지 계산.
			if (press < 0) {
				press = -press; // +를 누르는 경우.
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
