//  难点
// D. DS队列----银行单队列多窗口模拟
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t, p, k, sum = 0, maxwt = 0, dealtime = 0, wt = 0;
    cin >> n;
    queue<pair<int, int>> myQue;
    vector<pair<bool, int>> windows;
    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        myQue.push({t, p});
    }
    cin >> k;
    windows.resize(k, {true,
                       0}); //initialize vector<windows>, bool is that judging windows, true->open, false->close, int is that dealing time
    for (int worldtime = 0; !myQue.empty(); worldtime++) {
        if (worldtime >= myQue.front().first) {
            for (int i = 0; i < k; i++) {   //judging windows...
                if (windows[i].second <= worldtime) windows[i].first = true;
            }
            for (int i = 0; i < k; i++) {
                if (windows[i].first && worldtime >= myQue.front().first && !myQue.empty()) {
                    windows[i].first = false;
                    windows[i].second = worldtime + myQue.front().second;
                    wt = worldtime - myQue.front().first;
                    sum += wt;
                    myQue.pop();
                    if (wt > maxwt) maxwt = wt;
                    if (windows[i].second > dealtime) dealtime = windows[i].second;
                }
            }
        }
    }
    printf("%.1f %d %d", sum * 1.0 / n, maxwt, dealtime);
}