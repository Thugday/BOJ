#include <iostream>
#define MAX 51

using namespace std;

int a[MAX][MAX];
int b[MAX][MAX];

void flip(int x, int y) { // flip 연산 : x 행과 y열을 중심으로 3 x 3 을 뒤집어준다. 
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			a[i][j] = 1 - a[i][j];
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]); // 행렬 a 입력받기.
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &b[i][j]); // 행렬 b 입력받기.
		}
	}

	int sol(0);

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]){ // (i, j)가 서로 다르다면 (i+1, j+1)을 뒤집어준다.
				sol += 1;
				flip(i + 1, j + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) { // 끝까지 다르다면 행렬 문제를 풀 수 없기 때문에 -1 출력. 
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", sol);

	return 0;
}