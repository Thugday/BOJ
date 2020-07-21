#include <iostream>
#include <set>

using namespace std;

int main() {
	int n1;
	scanf("%d", &n1);

	multiset<int> s; // 같은 수가 허용되기에 multiset을 이용.
	for (int i = 0; i < n1; i++) {
		int m;
		scanf("%d", &m);
		s.insert(m); // multiset에 인풋 넣기.
	}

	int n2;
	scanf("%d", &n2);

	for (int i = 0; i < n2; i++) {
		int m;
		scanf("%d", &m);
		printf("%d ", s.count(m)); // count를 사용해 세주기.
	}

	printf("\n");

	return 0;

}