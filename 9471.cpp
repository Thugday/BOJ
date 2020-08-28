#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t; // 테스트 케이스 입력 받기.

	while (t--) {
		int n, m; 
		cin >> n >> m; // 테스트 케이스 번호, m입력 받기 

		int temp = 0; // 첫번 째 fibonacci.
		int temp2 = 1; // 두번 째 fibonacci.
		int ans = 0; // 반복하는 부분 수열의 길이.

		while (true) {
			if (temp == 0 && temp2 == 1 && ans != 0) {
				break;
			} // 예외처리, 주기가 반복 되면 while문 종료.
			int temp3 = temp;
			temp = temp2;
			temp2 = (temp + temp3) % m; // 주기를 확인하기위한 나머지 연산
			ans++;
		}

		cout << n << ' ' << ans << '\n'; // 테스트케이스 번호 및 정답 출력.
	}

	return 0;
}