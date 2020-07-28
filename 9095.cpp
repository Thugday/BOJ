#include <iostream>

using namespace std;

int d[11]; // n은 양수이며 11보다 작다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[0] = 1; // 예외 처리. d[0] 은  0 한가지의 방법 밖에 없다.
	for (int i = 1; i <= 10; i++) {
		if (i - 1 >= 0) { // 마지막에 1을 더해줄 경우 d[i-1]을 더해준다.
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) { // 마지막에 2를 더해줄 경우 d[i-2]을 더해준다.
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) { // 마지막에 3을 더해줄 경우 d[i-3]을 더해준다.
			d[i] += d[i - 3];
		}
	}


	int T;
	cin >> T; // 테스트 케이스 횟수 입력 받기.

	while (T--) { // 테스트 케이스로 출력.
		int n;
		cin >> n;
		cout << d[n] << "\n";
	}
	
	return 0;
}