#include <iostream>
#include <vector>
#define MAX 1000000 // 최대 백만.

using namespace std;

bool check[MAX+1]; // 소수가 아니면 true, 소수이면 false.
vector<int> prime;
int num;
bool flag;

void getPrime() {
	for (int i = 2; i <= MAX; i++) {
		if (check[i]) {
			continue;
		}
		prime.push_back(i);
		int temp = i;
		while (temp + i < MAX) {
			temp += i;
			check[temp] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	getPrime();
	while (true) {
		cin >> num;
		if (num == 0) {
			break;
		}
		flag = false;
		for (int i = 0; i < prime.size(); i++) {
			if (!check[num - prime[i]] && num - prime[i] > 2) {
				cout << num << " = " << prime[i] << " + " << num - prime[i] << '\n';
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}
	}
	return 0;
}