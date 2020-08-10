#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 양수, 음수 구별을 위한 변수 생성.
	vector<int> positive; 
	vector<int> negative;

	// 0과 1을 세주기 위한 변수 생성.
	int zero = 0;
	int one = 0;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 1) { // 1이 나올 경우 one 변수에 더해준다.
			one += 1;
		}
		else if (x > 0) { // 양수일 경우 양수 vector에 넣어준다.
			positive.push_back(x);
		}
		else if (x < 0) { // 음수일 경우 음수 vector에 넣어준다.
			negative.push_back(x);
		}
		else {
			zero += 1; // 남은 수는 0이기 때문에 zero 변수에 더해준다.
		}
	}

	// 양수는 큰 수끼리 묶어주고, 음수는 작은 수 끼리 묶어줘야 되므로 이에 맞게 정렬을 해준다.
	// 양수는 내림차순, 음수는 오름차순.
	sort(positive.begin(), positive.end());
	reverse(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());

	// 양수가 홀수인 경우에는 양수에 1을.
	if (positive.size() % 2 == 1) {
		positive.push_back(1);
	}

	// 음수가 홀수이면 0의 갯수에 따라 0을 넣어준다.
	if (negative.size() % 2 == 1) {
		negative.push_back(zero > 0 ? 0 : 1);
	}

	int sol = one;

	// 이제 짝수개인 양수 음수가 남았기때문에 2개씩 곱해서 더해준다.
	for (int i = 0; i < positive.size(); i+=2) {
		sol += positive[i] * positive[i + 1];
	}
	for(int i = 0; i < negative.size(); i+=2){
		sol += negative[i] * negative[i + 1];	
	}

	cout << sol << '\n';

	return 0;
}