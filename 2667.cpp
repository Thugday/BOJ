#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt;
int map[25][25]; // map을 사용해 정사각형 모양의 지도를 만들어줌.
int size_s[325]; // 집의 최대 갯수 : 325.
int d[4][2] = { {-1,0},{1,0},{0,-1},{0,1} }; // 위, 아래, 오른쪽, 왼쪽을 확인해줄 2차원 배열.

bool overdose(int a, int b) { // 배열을 초과하는지 확인.
	return (a >= 0 && a < n) && (b >= 0 && b < n);
}

void dfs(int x, int y, int cnt) { // 맵을 사용해 dfs 구현.
	map[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int dy = x + d[i][0];
		int dx = y + d[i][1];
		if (overdose(dy, dx) && map[dy][dx] == 1) {
			dfs(dy, dx, cnt);
		}
	}
}

void answer(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) { // map 이 1이면 cnt증가시킨 후 dfs로 이동.
				cnt++;
				dfs(i, j, cnt + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] > 1) { // 같은 숫자의 갯수를 더해 배열에 집어 넣어주기.
				size_s[map[i][j] - 2]++;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	answer(n);
	sort(size_s, size_s + cnt);

	cout << cnt << '\n';

	for (int i = 0; i < cnt; i++) {
		cout << size_s[i] << '\n';
	}

	return 0;
}