#include <iostream>

using namespace std;

void conversion(int n, int b) { // 10진법인 n을 b진법으로 바꿔준다.
	if (n == 0) {
		return;
	}
	else {
		conversion(n / b, b);
		cout << n % b << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, n;
	int x(0);
	
	cin >> a >> b; // a 진법과 b진법 input 받기.
	cin >> n; // a진법의 자리의 갯수 입력 받기.
	
	for (int i = 0; i < n; i++) { // 10진법으로 바꿔줘서 x로 저장.
		int num;
		cin >> num; // a진법의 숫자 입력받기.
		x = x * a + num; 
	}

	conversion(x, b);
	return 0;
}