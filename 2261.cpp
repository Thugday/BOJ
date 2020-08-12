#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Point {
	int x, y;
	Point() {
	}
	Point(int x, int y) : x(x), y(y){
	}
	bool operator < (const Point& v) const {
		if (x == v.x) {
			return y < v.y;
		}
		else {
			return x < v.x;
		}
	}
};


// y기준으로 비교하는 비교함수 구현.
bool cmp(const Point& u, const Point& v) {
	return u.y < v.y;
}

// 거리 계산 함수.
int dist(Point p1, Point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}


//Brute_Force 구현.
int bf(vector<Point>& a, int x, int y) {
	int ans = -1;
	for (int i = x; i <= y - 1; i++) {
		for (int j = i + 1; j <= y; j++) {
			int d = dist(a[i], a[j]);
			if (ans == -1 || ans > d) {
				ans = d;
			}
		}
	}
	return ans;
}

int closest(vector<Point>& a, int x, int y) {
	int n = y - x + 1;
	if (n <= 3) { // n이 3보다 작으면 brute_force 방식을 사용해 모든 점을 다 구해본다.
		return bf(a, x, y);
	}

	int mid = (x + y) / 2; // 가운데 점.
	int left = closest(a, x, mid); // 왼쪽 기준 가장 가까운 점.
	int right = closest(a, mid + 1, y); // 오른쪽 기준 가장 가까운 점.
	int ans = min(left, right); // 최소값
	vector<Point> b;
	for (int i = x; i <= y; i++) {
		int d = a[i].x - a[mid].x; // 가운데 점으로부터 점의 거리가 더 작으면
		if (d * d < ans) {
			b.push_back(a[i]); // b배열에 넣어준다.
		}
	}

	sort(b.begin(), b.end(), cmp); // y좌표 기준으로 b를 정렬해준다.
	int m = b.size();
	for (int i = 0; i < m - 1; i++) {
		for (int j = i + 1; j < m; j++) {
			int y = b[j].y - b[i].y; 
			// n^2 코드를 이용해서 모든 두 점의 쌍에 대해 계산해준다.
			if (y * y < ans) { 
				int d = dist(b[i], b[j]);
				if (d < ans) {
					ans = d;
				}
			}
			else {
				break; // break 가 있기 때문에 시간값이 : O(N).
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}

	sort(a.begin(), a.end()); // x 순으로 정렬.
	cout << closest(a, 0, n - 1) << '\n'; // 가장 가까운 점 호출.

	return 0;
}