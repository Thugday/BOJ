#include <iostream>
#define MAX 500000

using namespace std;

int d[MAX], b[MAX];


// 최대값이 10만이기때문에 머지소트를 사용해야 시간안에 풀 수 있다.
long long solve(int start, int end) {
	if (start == end) {
		return 0;
	}
	int mid = (start + end) / 2;
	long long ans = solve(start, mid) + solve(mid + 1, end);
	int i = start;
	int j = mid + 1;
	int k = 0;

	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || d[i] <= d[j])) {
			b[k++] = d[i++];
		}
		else {
			ans += (long long)(mid - i + 1); // 오른쪽에서 왼쪽으로 이동할때 합쳐주는 과정 생성.
			b[k++] = d[j++];
		}
	}

	for (int i = start; i <= end; i++) {
		d[i] = b[i - start];
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	long long ans = solve(0, n - 1);

	cout << ans << '\n';
	return 0;
}