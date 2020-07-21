#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	string line;
	while (cin >> line) {
		s += line;
	}

	istringstream sin(s); //문자열을 표준입출력처럼 사용하기 위해 istringstream 사용.

	string num;
	int sum(0);

	while (getline(sin, num, ',')) {
		sum += stoi(num);
	}

	cout << sum << '\n';
	return 0;
}