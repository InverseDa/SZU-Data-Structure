//
// DS-堆栈-表达式求值
//
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
#include <iomanip>


using namespace std;

#define OK 0
#define ERROR -1
#define OPSETSIZE 7
typedef int Status;

char Prior[7][7] = {'>', '>', '<', '<', '<', '>', '>', '>', '>', '<', '<', '<', '>', '>', '>', '>', '>', '>', '<', '>',
                    '>', '>', '>', '>', '>', '<', '>', '>', '<', '<', '<', '<', '<', '=', ' ', '>', '>', '>', '>', ' ',
                    '>', '>', '<', '<', '<', '<', '<', ' ', '='};

float Operate(float a, unsigned char theta, float b) {
    if (theta == '+') return a + b;
    if (theta == '-') return a - b;
    if (theta == '*') return a * b;
    if (theta == '/') return a / b;

    return ERROR;
}

char OPSET[OPSETSIZE] = {'+', '-', '*', '/', '(', ')', '#'};

Status In(char Test, const char *TestOp) {
    for (int i = 0; i < 7; i++)
        if (Test == TestOp[i]) return 1;
    return OK;
}

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

float EvaluateExpression(string MyExp) {
    stack<char> OPTR;   //运算符栈
    stack<double> OPND; //操作数栈
    char TempData[20];
    double Data, a, b;
    char theta, Dr[2];  //theta是符号， Dr[2]记录数据（因为比如52+2*3，52是一个数，所以Dr记录一位5，并给TempData）
    char c; //字符串中每个字符的记录者
    int i = 0;  //字符在字符串的位置
    OPTR.push('#');
    c = MyExp[0];

    strcpy(TempData, "\0"); //初始化TempData为“0”
    while (c != '#' || OPTR.top() != '#') {
        if (!In(c, OPSET)) {
            //把数记录到Tempdata
            Dr[0] = c;
            Dr[1] = '\0';
            strcat(TempData, Dr);
            c = MyExp[++i];
            if (In(c, OPSET)) { //如果字符下一位是运算符，那么就直接转换字符串为浮点数，并入操作数栈内
                Data = (float) stof(TempData);
                OPND.push(Data);
                strcpy(TempData, "\0"); //初始化
            }
        } else {
            switch (precede(OPTR.top(), c)) {
                case '<':
                    OPTR.push(c);
                    c = MyExp[++i];
                    break;
                case '=':
                    OPTR.pop();
                    c = MyExp[++i];
                    break;
                case '>':
                    theta = OPTR.top();
                    OPTR.pop();
                    b = (float) OPND.top();
                    OPND.pop();
                    a = (float) OPND.top();
                    OPND.pop();
                    OPND.push(Operate(a, theta, b));
                    break;
            }
        }
    }
    return OPND.top();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        float res = EvaluateExpression(str);
        cout << fixed << setprecision(4) << res << endl;
    }
}
