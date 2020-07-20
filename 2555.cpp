#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	auto birth = [] {
		cout << "10/14" << '\n';
	};
	birth();

	return 0;
}

