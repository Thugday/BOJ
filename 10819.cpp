#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// |A[0]-A[1]| + |A[1]-A[2]| + ... + |A[N-2]-A[N-1]|식 계산 함수.
int calc(vector<int> &v) {
	int sum = 0;
	for (int i = 1; i < v.size(); i++) {
		sum += abs(v[i] - v[i - 1]);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i]; // 배열 입력 받기.
	}

	sort(v.begin(), v.end()); // 오름차순으로 정렬

	int ans(0);
	

	// next_permutation을 이용해 모든 순열에 대해서 값을 계산해준다.
	do {
		int temp = calc(v);
		ans = max(ans, temp);
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << '\n';
	return 0;
}