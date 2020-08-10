#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Meeting { // 회의 구조체 생성(시작시간과 끝나는 시간).
	int begin, end;
};


bool cmp(const Meeting& u, Meeting& v) { // 비교함수 만들기.
	if (u.end == v.end) { // 끝나는 시간이 같은경우 시작지점도 비교해줘야된다.
		return u.begin < v.begin;
	}
	else {
		return u.end < v.end;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Meeting> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i].begin >> v[i].end; // 회의에 따른 시작시간, 끝나는 시간 입력 받기.
	}
	
	sort(v.begin(), v.end(), cmp); // 시작시간을 기준으로 정렬을 해준다

	int time(0), sol(0);

	for (int i = 0; i < v.size(); i++) { // 회의의 최대값 찾기.
		if (time <= v[i].begin) {
			time = v[i].end;
			sol += 1;
		}
	}

	cout << sol << '\n';

	return 0;
}