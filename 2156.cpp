#include <iostream>

using namespace std;

long long d1[10001];
long long d2[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> d1[i]; // 잔에 갯수에 따른 포도주의 양들을 입력 받기.
	}

	d2[1] = d1[1]; // 한 잔만 있을 경우 바로 마시면 된다.
	d2[2] = d1[1] + d1[2]; // 두잔이 있을경우 음수값이 아니기 때문에 두 잔을 모두 마시면 최대 값이 된다.

	for (int i = 3; i <= t; i++) { //세 잔부터는 연속으로 마실 수 없기 때문에 3을 시작 값으로 둔다.
		d2[i] = d2[i - 1]; // 0번 연속해서 마신 포도주.
		if (d2[i] < d2[i - 2] + d1[i]) { // 1번 연속해서 마신 포도주.
			d2[i] = d2[i - 2] + d1[i];
		}

		if (d2[i] < d2[i - 3] + d1[i] + d1[i - 1]) { // 2번 연속해서 마신 포도주.
			d2[i] = d2[i - 3] + d1[i] + d1[i - 1];
		}
	}

	cout << d2[t] << '\n';

	return 0;

}