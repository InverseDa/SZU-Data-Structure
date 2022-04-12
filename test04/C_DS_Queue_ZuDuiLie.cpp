//
// C. DS队列--组队列
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, first = -1;
    string operate;
    cin >> n;
    vector<queue<int>> myQue(n);
    vector<int> cnt(n, -1), final;
    unordered_map<int, int> m;
    for (int j = 0; j < n; j++) {
        int size, val;
        cin >> size;
        for (int i = 0; i < size; i++) {
            cin >> val;
            m[val] = j;
        }
    }
    while (true) {
        cin >> operate;
        if (operate == "STOP") break;
        if (operate == "ENQUEUE") {
            int val;
            cin >> val;
            if (first == -1) {
                first = m[val];
                cnt[m[val]] = 0;
                myQue[cnt[m[val]]].push(val);
                continue;
            } else {
                if (cnt[m[val]] == -1) {
                    for (int i = 0; i < n; i++) {
                        if (myQue[i].empty()) {
                            cnt[m[val]] = i;
                            myQue[i].push(val);
                            break;
                        }
                    }
                } else {
                    myQue[cnt[m[val]]].push(val);
                }
            }
        }
        if (operate == "DEQUEUE") {
            for (int i = 0; i < n; i++) {
                if (!myQue[i].empty()) {
                    final.push_back(myQue[i].front());
                    myQue[i].pop();
                    break;
                }
            }
        }
    }
    for (auto it = final.begin(); it != final.end(); it++) {
        if (it != final.begin()) cout << ' ';
        cout << *it;
    }

}