#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s; 
	cin >> s; // string 형태로 숫자와 기호를 받아준다.

	vector<int> n;
	vector<int> sign;

	bool negative = false;
	
	int par = 0;
	sign.push_back(1);

	for (int i = 0; i < s.size(); i++) { // 숫자와 기호를 번갈아 가며 누적해준다.
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+') { 
				sign.push_back(1);
			}
			else {
				sign.push_back(-1);
			}
			n.push_back(par);
			par = 0;
		}
		else {
			par = par * 10 + (s[i] - '0');
		}
	}

	n.push_back(par);
	
	int sol(0);
	negative = false;
	for (int i = 0; i < n.size(); i++) { // 첫번쨰 음수가 나왔을때 계속 빼준다.
		if (sign[i] == -1) { 
			negative = true;
		}
		if (negative) {
			sol -= n[i];
		}
		else {
			sol += n[i];
		}
	}
	cout << sol << '\n';
	return 0;
}