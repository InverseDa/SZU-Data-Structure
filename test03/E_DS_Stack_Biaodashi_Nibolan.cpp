//
// DS-堆栈-表达式求值-逆波兰表达式
//

#include <iostream>
#include <stack>

using namespace std;

char Prior[7][7] = {'>', '>', '<', '<', '<', '>', '>', '>', '>', '<', '<', '<', '>', '>', '>', '>', '>', '>', '<', '>',
                    '>', '>', '>', '>', '>', '<', '>', '>', '<', '<', '<', '<', '<', '=', ' ', '>', '>', '>', '>', ' ',
                    '>', '>', '<', '<', '<', '<', '<', ' ', '='};

char precede(char Aop, char Bop) {
    int r1, r2;
    if (Aop == '+') r1 = 0;
    if (Aop == '-') r1 = 1;
    if (Aop == '*') r1 = 2;
    if (Aop == '/') r1 = 3;
    if (Aop == '(') r1 = 4;
    if (Aop == ')') r1 = 5;
    if (Aop == '#') r1 = 6;

    if (Bop == '+') r2 = 0;
    if (Bop == '-') r2 = 1;
    if (Bop == '*') r2 = 2;
    if (Bop == '/') r2 = 3;
    if (Bop == '(') r2 = 4;
    if (Bop == ')') r2 = 5;
    if (Bop == '#') r2 = 6;
    return Prior[r1][r2];
}

float EvaluateExpression(string str) {
    stack<char> s;
    int flag = 0;
    string nibolan;
    for (char &i : str) {
        if (i == '#') break;
        if (isdigit(i)) nibolan.push_back(i);
        else {
            if (i == '(') flag = 1;
            if (flag && i == ')') {
                for (int j = 0;; j++) {
                    if (s.top() == '(') {
                        s.pop();
                        break;
                    }
                    nibolan.push_back(s.top());
                    s.pop();
                }
            }
            s.push(i);
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

    }
}