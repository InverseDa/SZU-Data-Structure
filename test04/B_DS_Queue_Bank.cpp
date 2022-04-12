//
// B. DS队列之银行排队
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    int sum[3] = {0}, ave[3] = {0}, cnt[3] = {0};
    cin >> n;
    queue<char> myQue;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        myQue.push(ch);
    }
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        sum[myQue.front() - 'A'] += val;
        cnt[myQue.front() - 'A']++;
        myQue.pop();
    }
    for (int i = 0; i < 3; i++) {
        ave[i] = sum[i] / cnt[i];
        cout << ave[i] << endl;
    }

}