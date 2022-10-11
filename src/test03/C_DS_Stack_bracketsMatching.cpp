//
// DS-堆栈-括号匹配
//

#include <stack>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        stack<char> s;
        string str;
        cin >> str;
        for (auto &i : str) {
            if (i == '(' || i == '[' || i == '{') {
                s.push(i);
                continue;
            }
            if (i == ')' && s.top() == '(') s.pop();
            if (i == ']' && s.top() == '[') s.pop();
            if (i == '}' && s.top() == '{') s.pop();
        }
        if (s.empty()) cout << "ok" << endl;
        else cout << "error" << endl;
    }
}
