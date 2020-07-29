#include <iostream>
#include <algorithm>


using namespace std;

// d[i][j] = 2xi에서 얻을 수 있는 최대 점수, i번 열에서 j 스티커 뜯기.
long long d1[100001][2];
long long d2[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t; // 테스트 케이스 입력받기.

	while (t--) { 
		int n; // 한 줄의 스티커 갯수 입력 받기.
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> d1[i][0]; // 위쪽 줄의 스티커 점수 입력 받기.
		}

		for (int i = 1; i <= n; i++) {
			cin >> d1[i][1]; // 아래쪽 줄의 스티커 점수 입력 받기.
		}

		d2[0][0] = d2[0][1] = d2[0][2] = 0; // 아무것도 뜯지 않았을 때 0.
		
		for (int i = 1; i <= n; i++) {
			d2[i][0] = max(d2[i - 1][0], max(d2[i - 1][1], d2[i - 1][2])); // 마지막 줄을 뜯지 않았을 때, i-1은 뜯지 않을수도, 위쪽을 뜯을 수도, 아래쪽을 뜯을 수도 있다.
			d2[i][1] = max(d2[i - 1][0], d2[i - 1][2]) + d1[i][0]; // 마지막줄에서 위쪽을 뜯을경우, i-1은 아무것도 뜯지 않을 수도있고, 아래쪽을 뜯었을 수 있다. 마지막을 뜯었으니 d1[i][0]을 더해줌.
			d2[i][2] = max(d2[i - 1][0], d2[i - 1][1]) + d1[i][1]; // 마지막줄에서 아래쪽을 뜯을경우, i-1은 아무것도 뜯지 않을 수도있고, 위쪽을 뜯었을 수 있다. 마지막을 뜯었으니 d1[i][0]을 더해줌.
		}

		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(max(ans, d2[i][0]), max(d2[i][1], d2[i][2])); // 세가지의 경우의 수에서 max 값을 찾아준다.
		}

		cout << ans << '\n';
	}

	return 0;
}