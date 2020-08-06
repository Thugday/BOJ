#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // 갯수 입력 받기.
	vector <pair<int, int>> a(n); 

	for (int i = 0; i < n; i++) {
		cin >> a[i].first; // 숫자 저장.
		a[i].second = i; // 인덱스 저장.
	}

	sort(a.begin(), a.end()); // sort 사용, 오름차순으로 정렬.

	int x(0);
	for (int i = 0; i < n; i++) { // 정렬 된 후의 인덱스.
		if (x < a[i].second - i) { // 정렬되기 전과 후의 index 차를 비교.
			x = a[i].second - i;
		}
	}

	cout << x + 1 << '\n'; // 1을 더해줌으로써 index가 1부터 시작하는 것을 보정.

	return 0;

}