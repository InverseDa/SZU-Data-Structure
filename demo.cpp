#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <iomanip>
#include <unordered_set>

using namespace std;

int main() {
    int t, k, temp, front;
    string str;
    cin >> t;
    auto *que = new queue<int>[1000];
    vector<int> check(10000, -1);
    vector<int> al(10000);
    queue<int> next;
    for (int i = 0; i < t; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> temp;
            check[temp] = i;
        }
    }
    while (str != "STOP") {
        cin >> str;
        if (str == "ENQUEUE") {
            cin >> temp;
            int lambda = check[temp];
            if (lambda >= 0) {
                if (!al[lambda]) {
                    next.push(lambda);
                    al[lambda] = 1;
                }
                que[lambda].push(temp);
            } else que[t - 1].push(temp);
        } else if (str == "DEQUEUE") {
            front = next.front();
            cout << que[front].front() << " ";
            que[front].pop();
            if (que[front].empty()) {
                al[front] = 0;
                next.pop();
            }
        }
    }
    delete[] que;
    return 0;
}