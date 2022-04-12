
//
// DS-堆栈-行编辑
//
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        stack<char> s;
        string str;
        cin >> str;
        for (char &i : str) {
            if (i != '#') s.push(i);
            else if (!s.empty()) {
                s.pop();
            }
        }
        int size = s.size();
        if (size) {
            vector<char> output;
            for (int i = 0; i < size; i++) {
                output.push_back(s.top());
                s.pop();
            }
            for (auto it = output.rbegin(); it != output.rend(); it++)
                cout << *it;
        } else cout << "NULL";
        cout << endl;
    }
}
