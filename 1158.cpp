#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i); // 큐에 value 저장하기.
    }

    cout << "<";
    
    for (int i = 0; i < n - 1; i++) { // n만큼 실행
        for (int j = 0; j < m - 1; j++) { // m만큼 실행.
            q.push(q.front()); // 맨 앞 value를 뒤로 push.
            q.pop(); // 맨 앞 pop. 
        }
        cout << q.front() << ", ";
        q.pop(); // 모두 돌아갔을 시 맨 앞 pop.
    }
    cout << q.front() <<">" << '\n';
    return 0;
}