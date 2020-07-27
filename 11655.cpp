#include <iostream>
#include <string>

using namespace std;

// a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z.
string ROT13(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'm') {
			s[i] = s[i] + 13; // a부터 m 단어에 +13 해주기.
		}
		else if (s[i] >= 'n' && s[i] <= 'z') {
			s[i] = s[i] - 13; // n부터 z 단어는 +13을 해주면 대문자로 표시되기때문에 -13을 해줌.
		}
		else if (s[i] >= 'A' && s[i] <= 'M') { // A부터 M 단어에 +13 해주기.
			s[i] = s[i] + 13;
		}
		else if (s[i] >= 'N' && s[i] <= 'Z') { // N부터 Z 단어 -13 해주기.
			s[i] = s[i] - 13;
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	getline(cin, s); // 한 줄 입력 받기.

	cout << ROT13(s) << '\n';

	return 0;
}