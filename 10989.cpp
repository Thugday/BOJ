#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10000

using namespace std;

int m[MAX + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; 
	cin >> t; // 갯수 입력 받기.
	
	int temp;
	for (int i = 0; i < t; i++) {
		cin >> temp; // 갯수에 따른 숫자 입력 받기.
		m[temp] += 1; // m 변수 1씩 증가 시킴으로 숫자 갯수 세주기.
	}

	// m[i]가 0보다 크면 각 숫자를 갯수만큼 출력해주기.
	for (int i = 0; i <= MAX; i++) {
		if (m[i] > 0) {
			for (int j = 0; j < m[i]; j++) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}