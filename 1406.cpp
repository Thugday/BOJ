#include <iostream>
#include <stack>
#include <cstring>
#define MAX 600000

using namespace std;

char c[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c; // 초기 문자열 받아주기.
    stack<char> left, right; // 커서 기준 양 옆 스택 성능을 이용하기 위해 분리.
    int n = strlen(c);

    for (int i = 0; i < n; i++) {
        left.push(c[i]);
    }

    int m;
    cin >> m;

    while (m--) {
        char cmd;
        cin >> cmd;
        if (cmd == 'L') { 
            if (!left.empty()) { // 왼쪽이 비어있으면 커서가 가장 왼쪽.
                right.push(left.top());
                left.pop();
            }
        }
        else if (cmd == 'D') {
            if (!right.empty()) { // 오른쪽이 비어있으면 커서가 가장 오른쪽.
                left.push(right.top());
                right.pop();
            }
        }
        else if (cmd == 'B') {
            if (!left.empty()) {
                left.pop();
            }
        }
        else if (cmd == 'P') {
            char x;
            cin >> x;
            left.push(x);
        }
    }

    while (!left.empty()) { // 처음부터 출력해줘야되기 때문에 왼쪽 value를 다 오른쪽으로 옮겨준다.
        right.push(left.top());
        left.pop();
    }

    while (!right.empty()) { // 맨위부터 출력해주면서 pop해주기.
        cout << right.top();
        right.pop();
    }

    cout << '\n';
    return 0;
}

