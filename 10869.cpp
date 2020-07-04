#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b;
	cin >> a >> b;

	vector<function<int(int, int)>> v;
	v.push_back([](int a, int b) {
		return a + b; 
	});
	v.push_back([](int a, int b) {
		return a - b;
		});
	v.push_back([](int a, int b) {
		return a * b;
		});
	v.push_back([](int a, int b) {
		return a / b;
		});
	v.push_back([](int a, int b) {
		return a % b;
		});

	for (auto &x : v) {
		cout << x(a, b) << '\n';
	}
}