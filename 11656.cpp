#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	string s2[1000];
	cin >> s;
	
	int l = s.length();
	for (int i = 0; i < l; i++) {
		s2[i] = s.substr(i, l); // substr을 이용하여 i 만큼씩 단어의 앞 알파벳을 뺀 접미사 저장.
	}

	sort(s2, s2 + l); // 사전순으로 접미사 정리.
	for (int i = 0; i < l; i++) {
		cout << s2[i] << '\n'; // 사전순으로 정리된 접미사를 출력.
	}

	return 0;
}