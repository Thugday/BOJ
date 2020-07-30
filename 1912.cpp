#include <iostream>
#include <algorithm>
#define MAX 100001 // 최대 100000.

using namespace std;

int d[MAX]; 
int d2[MAX]; 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; 
	cin >> n;
	
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		cin >> d2[i]; // n까지의 수열의 값 받기.
	}

	d[0] = d2[0]; // 예외처리, 0번째로 끝나는 가장 큰 연속의 합은 0이 된다.
	ans = d[0];

	for (int i = 1; i < n; ++i) // 1부터 n까지 시작지점을 늘려주며 비교한다.
	{
		d[i] = max(d[i - 1] + d2[i], d2[i]); // d[i-1] + d2[i]를 계속 해주고, 그 중 max 값을 찾아준다.
		if (ans < d[i]) // 만약 이 전 루프의 답보다 크다면 그 루프가 제일 큰 연속합.
		{
			ans = d[i];
		}
	}

	cout << ans << "\n";
}
