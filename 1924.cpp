#include <iostream>
#include <string>

using namespace std;

class calender { // 객체지향
private:
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // 월마다 다른 일수로 저장.
	string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" }; // 요일 저장.
	int x, y;
	int n;

public:
	void Date() { // 인풋 x월 y일 받기.
		cin >> x >> y;
		n = 0;
	}

	void calculation() { // 날짜 계산하기.
		for (int i = 0; i < x - 1; i++) {
			y += month[i];
		}
		n = y % 7;
	}

	void print() { // 요일 아웃풋.
		cout << day[n];
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	calender c;
	c.Date();
	c.calculation();
	c.print();

	return 0;
}