#include <iostream>
#include <algorithm>

using namespace std;

long long m[5000001]; // 최대 5000000.

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k; // 갯수와, 구할 자리의 수 입력 받기.

	k -= 1;

	for (int i = 0; i < n; i++) {
		cin >> m[i]; // 갯수에 따른 숫자 입력 받기.
	}

	nth_element(m, m + k, m + n); // STL에 있는 nth_element 구현. 
	// m 부터 m + k 까지 를 정렬, 총 길이는 m + n.

	cout << m[k] << '\n';

	return 0;
}