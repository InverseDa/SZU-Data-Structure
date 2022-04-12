//
// E. 计算2支股票的M天运动平均价格
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class gupiao {
public:
    string date, mode;
    int s1, s2;
};

bool cmp(const gupiao &a, const gupiao &b) {
    return a.date < b.date;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<gupiao> fileclose;
    vector<gupiao> fileopen;
    for (int i = 0; i < n; i++) {
        string date, mode;
        int s1, s2;
        cin >> date >> mode >> s1 >> s2;
        if (mode == "close") fileclose.push_back({date, mode, s1, s2});
        else fileopen.push_back({date, mode, s1, s2});
    }
    sort(fileopen.begin(), fileopen.end(), cmp);
    sort(fileclose.begin(), fileclose.end(), cmp);

    for (int i = 0; i < fileopen.size() - 1; i++) {
        int cnt = 0, sum1 = 0, sum2 = 0;
        for (int j = i + 1; j < fileopen.size(); j++) {
            sum1 += fileopen[i].s1 + fileopen[j].s1;
            sum2 += fileopen[i].s2 + fileopen[j].s2;
            if (++cnt == m - 1) {
                int arc1 = sum1 / m, arc2 = sum2 / m;
                cout << fileopen[j].date << ' ' << fileopen[j].mode << ' ' << arc1 << ' ' << arc2 << endl;
                break;
            }
        }
    }

    for (int i = 0; i < fileclose.size() - 1; i++) {
        int cnt = 0, sum1 = 0, sum2 = 0;
        for (int j = i + 1; j < fileclose.size(); j++) {
            sum1 += fileclose[i].s1 + fileclose[j].s1;
            sum2 += fileclose[i].s2 + fileclose[j].s2;
            if (++cnt == m - 1) {
                int arc1 = sum1 / m, arc2 = sum2 / m;
                cout << fileclose[j].date << ' ' << fileclose[j].mode << ' ' << arc1 << ' ' << arc2 << endl;
                break;
            }
        }
    }
}