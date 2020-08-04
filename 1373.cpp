#include <iostream>
#include <map>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	int n(0);

	deque<char> sol;
	map<string, char> map;

	// map을 사용해 2진수를 0부터 7까지 세개씩 끊어서 저장해준다.
	map["000"] = '0'; 
	map["001"] = '1';
	map["010"] = '2';
	map["011"] = '3';
	map["100"] = '4';
	map["101"] = '5';
	map["110"] = '6';
	map["111"] = '7';

	cin >> s;
	int size = s.size();

	// 2진수를 8진수로 바꿔준다.
	if (size == 1 && s[0] == '0') {
		cout << 0;
	}
	else {
		while (true) {
			if (size - n >= 3) {
				sol.push_front(map[s.substr(size - 3 - n, 3)]);
			}
			else if (size - n == 2)
			{
				s = '0' + s.substr(0, 2);
				sol.push_front(map[s]);
			}
			else if (size - n == 1)
			{
				s = "00" + s.substr(0, 1);
				sol.push_front(map[s]);
			}
			else
				break;
			n += 3;
		}

		size = sol.size();
		for (int i = 0; i < size; i++) {
			cout << sol[i];
		}
	}
	return 0;
}