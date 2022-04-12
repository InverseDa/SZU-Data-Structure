//
//  DS栈+队列—排队游戏
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    stack<pair<char, int>> myS;
    queue<pair<int, int>> myQ;
    string str;
    cin >> str;
    myS.push({str[0], 0});
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[0]) myS.push({str[i], i});
        else {
            myQ.push({myS.top().second, i});
            myS.pop();
        }
    }
    int len = myQ.size();
    for (int i = 0; i < len; i++) {
        cout << myQ.front().first << ' ' << myQ.front().second << endl;
        myQ.pop();
    }
}