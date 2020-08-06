#include <iostream>
#include <algorithm>

using namespace std;

long long m[1000001]; // 최대 숫자 카드의 갯수 100000.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // 카드의 갯수 입력 받기.

	for (int i = 0; i < n; i++) {
		cin >> m[i]; // 카드에 적혀있는 정수 입력 받기.
	}

	sort(m, m + n); // sort 사용 정렬해주기.

	long long x = m[0];
	int x_cnt(1), cnt(1);

	for (int i = 1; i < n; i++) {
		if (m[i] == m[i - 1]) { // 이전 카드와 같다면 중복되기 때문에 cnt 1 증가.
			cnt += 1;
		}
		else {
			cnt = 1; // 이전 카드와 다른 경우 cnt 값을 1로 초기화.
		}
		if (x_cnt < cnt) { // 어떤 수가 제일 많이 반복되는지 마지막으로 구해준다.
			x_cnt = cnt;
			x = m[i];
		}
	}
	cout << x << '\n';

	return 0;
}