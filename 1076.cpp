#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	map<string, int> m = { {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
							{"grey", 8}, {"white", 9} }; // string을 정수로 변환시켜주기 위해 map사용.
	string x, y, z;
	cin >> x >> y >> z;

	long long num = (long long)((m[x] * 10) + m[y]);
	for (int i = 0; i < m[z]; i++) {
		num *= 10LL;
	}

	cout << num << '\n';

	return 0;
}