#include <iostream>

using namespace std;


int gcd(int a, int b) { // 재귀함수를 통해 구현한 유클리드 호제법, 최대공약수 구하기.
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);
	int l = (a * b) / g; // L * G = A * B 를 통한 최소공배수 구하기.
 
	cout << g << '\n';
	cout << l << '\n';

	return 0;

}