#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 증명:
  S = n*p1 + ... + (n-(i-1))*pi + ... + (n-(j-1))*pj + ... + pn.
  S` = n*p1 + ... + (n-(i-1))*pj + ... + (n-(j-1))*pi + ... + pn.
  오름차순이 정답이면, pi 와 pj의 순서를 바꿨을때, 더 커지거나 같아야된다.
  S-S` = (n-i+1)*pi + (n-j+1)*pj - (n-i+1)*pj - (n-j+1)*pi.
  = (n-i+1-n+j-1)pi + (n-j+1-n+i-1)*pj
  = (j-i)pi + (i-j)pj
  = -(i-j)pi + (i-j)pj
  = (i-j)(pj-pi)
  i-j 는 0보다 작고 Pj-Pi는 0보다 크거나 같기 때문에 항상 0보다 작거나 같게 된다.
  즉, Pi와 Pj의 순서를 바꿔도 참.
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n; // 사람의 수 입력 받기.

	vector<int> v(n);

	for(int i = 0; i < n; i++) {
		cin >> v[i]; // 돈 인출 시간 입력 받기.
	}
	sort(v.begin(), v.end()); // 오름차순으로 정렬해주기.

	int sum(0), time(0);
	
	for (int i = 0; i < v.size(); i++) { // 사이즈에 따른 앞에서 부터 누적합 time에 더해주기. 
		sum += v[i];
		time += sum;
	}

	cout << time << '\n';

	return 0;
}