#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double x, y, c;


// h = h1*h2 / (h1+h2). 
double calc(double mid) {
	double h1 = sqrt(x * x - mid * mid);
	double h2 = sqrt(y * y - mid * mid);

	return (h1 * h2) / (h1 + h2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> x >> y >> c;

	double lhs = 0, rhs = min(x, y);
	double ans = 0;


	// 실수이기 때문에 lhs <= rhs  불가능.
	while (rhs - lhs > 0.000001) {
		double mid = (rhs + lhs) / 2.0;
		if (calc(mid) >= c) {
			ans = mid;
			lhs = mid;
		}
		else {
			rhs = mid;
		}
	}
	printf("%.3lf\n", ans);
	return 0;
}