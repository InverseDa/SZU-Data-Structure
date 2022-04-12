//
// A. DS队列+堆栈--数制转换
//
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

char nums[] = {"0123456789ABCDEF"};

void trans(float number, int k) {
    int integer = (int) number;
    float fl = number - (float) integer;
    string res;
    stack<char> in;
    queue<char> flo;
    while (integer != 0) {
        in.push(nums[integer % k]);
        integer /= k;
    }
    if (fl != 0) {
        while (fl < 1) {
            flo.push(nums[(int) (fl * k)]);
            fl *= k;
        }
    }
    int len1 = in.size(), len2 = flo.size(), dotpos = 0;
    for (int i = 0; i < len1; i++) {
        res.push_back(in.top());
        in.pop();
    }
    if (!flo.empty()) {
        res.push_back('.');
        dotpos = res.size();
        for (int i = 0; i < len2; i++) {
            res.push_back(flo.front());
            flo.pop();
        }
    }
    cout << fixed << setprecision(3);
    if (dotpos == 0) cout << res << endl;
    else {
        res = res.substr(0, dotpos - 1) + "." + to_string(stof("0." + res.substr(dotpos))).substr(2, 3);
        cout << res << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        float number;
        int k;
        cin >> number >> k;
        trans(number, k);
    }
}