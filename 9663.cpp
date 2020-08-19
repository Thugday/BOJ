#include <iostream>
#define MAX 16

using namespace std;

bool a[MAX][MAX];
int n;
bool check_col[MAX];
bool check_diag[40];
bool check_diag2[40];

bool check(int row, int col) {
	// 열에 있을 때. (|)
	if (check_col[col]) {
		return false;
	}
	
	// 왼쪽 위 대각선. (\)
	if (check_diag[row + col]) {
		return false;
	}
	
	// 오른쪽 위 대각선. (/)
	if (check_diag2[row - col +n]) {
		return false;
	}
	return true;
}

int solve(int row) {
	// 정답을 찾은 경우.
	if (row == n) {
		// ans += 1;
		return 1;
	}

	int cnt = 0;
	for (int col = 0; col < n; col++) {
		// 퀸을 놓을 수 있을시
		if (check(row, col)) {
			check_diag[row + col] = true;
			check_diag2[row - col + n] = true;
			check_col[col] = true;
			a[row][col] = true; 
			// 모두 true를 넣어준다.
			cnt += solve(row + 1); 
			// 호출이 끝났으면 false로 초기화 시켜준다.
			check_diag[row + col] = false;
			check_diag2[row - col + n] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	cout << solve(0) << '\n';
	return 0;
}
