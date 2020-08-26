#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

long long d[MAX][21]; // 최대 총 수는 100개, 만들 수 있는 수는 20개

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	n -= 1;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int ans;
	cin >> ans;

	//d[i][j] = i번째 수까지 사용하여 j를 만드는 방법의 수.
	d[0][v[0]] = 1; // 제일 처음에는 -나 +가 올 수 없다.
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - v[i] >= 0) { // -가 오는경우.
				d[i][j] += d[i - 1][j - v[i]];
			}
			if (j + v[i] <= 20) { // +가 오는 경우.
				d[i][j] += d[i - 1][j + v[i]];
			}
		}
	}

	cout << d[n - 1][ans] << '\n';
	return 0;
}