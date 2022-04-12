//
// DS-堆栈-逆序输出
//
#include <stack>
#include <iostream>

using namespace std;

int main() {
    string str;
    int size, t;
    stack<char> cs;
    cin >> t;
    cin.get();
    while (t--) {
        getline(cin, str);
        for (char &i : str) {
            cs.push(i);
        }
        size = cs.size();
        for (int i = 0; i < size; i++) {
            cout << cs.top();
            cs.pop();
        }
        cout << endl;
    }
}
