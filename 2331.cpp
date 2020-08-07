#include <iostream>

using namespace std;

int check[1000000];

int power(int x, int p) { // 어떤 수를 p번 곱해준다.
	int temp = 1;
	for (int i = 0; i < p; i++) {
		temp = temp * x;
	}
	return temp;
}

int next(int a, int p) { // 어떤 수를 10으로 나눠주며 각 자리 수를 p번 곱한 값을 누적.
	int temp = 0;
	while (a > 0) {
		temp += power(a % 10, p);
		a /= 10;
	}
	return temp;
}

int length(int a, int p, int cnt) { // dfs대신 length 함수를 만들어서 써줌.
	if (check[a] != 0) { // check[a]가 0이 아니라면 몇 번째 방문인지 확인.
		return check[a] - 1; 
	}
	check[a] = cnt; 
	int b = next(a, p); // 다음 수 b는 cnt + 1 이 된다.
	return length(b, p, cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, p;
	cin >> a >> p;
	cout << length(a, p, 1) << '\n';

	return 0;
}