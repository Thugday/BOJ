#include <iostream>
#include <algorithm>
#define MAX 1000001

using namespace std;

int heap[MAX];
int temp;

int pop() {
	int sol = heap[1];
	heap[1] = heap[temp];
	heap[temp--] = 0;
	for (int i = 1; i * 2 <= temp;) {
		// 두 자식 보다 클때.
		if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1]) {
			break;
		}
		// 두 자식보다 크지 않을 때 swap 실행.
		else if (heap[i * 2] > heap[i * 2 + 1]) {
			swap(heap[i], heap[i * 2]);
			i = i * 2;
		}
		else {
			swap(heap[i], heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}
	return sol;
}

// heap에 원소가 몇 개인지 구해주는 함수.
void push(int x) {
	heap[++temp] = x;
	for (int i = temp; i > 1; i /= 2) {
		if (heap[i / 2] < heap[i]) { // 최대힙이 아닐 때 swap 실행.
			swap(heap[i / 2], heap[i]);
		}
		else {
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (temp == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << pop() << '\n';
			}
		}
		else {
			push(x);
		}
	}
	return 0;
}