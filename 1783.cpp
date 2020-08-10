#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	if (n == 1) { // 높이가 1인경우 움직일 수 없기 때문에 1이다.
		cout << 1;
	}
	else if (n == 2) {
		cout << min(4, (m + 1) / 2); // 높이가 2인 경우 ((너비 + 1) / 2) 와 4(이동제한) 중 최소값. 
	}
	else if (n >= 3) { // 높이가 3인경우
		if (m >= 7) { // 모든 경우를 한 번씩 사용했을 경우, 너비가 7 이상이 된다.
			cout << m - 2; // 여기서 위로 한칸 오른쪽 두칸과, 밑으로 한칸 오른쪽 두칸을 사용하게 될때 공백이 1씩 발생함. 고로 -2.
		}
		else { 
			cout << min(4, m); // 너비가 7 미만일경우, 4가지 행동을 다 할 수 없으므로 4와 너비의 최소값이 된다.
		}
	}
	cout << '\n';

	return 0;
}

