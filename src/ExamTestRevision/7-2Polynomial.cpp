//
// Created by inver on 2021/12/13.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> pa, pair<int, int> pb) {
    return pa.second > pb.second;
}

list<pair<int, int>> add(list<pair<int, int>> l1, list<pair<int, int>> l2) {
    /****加法实现****/
    auto it1 = l1.begin(), it2 = l2.begin();
    list<pair<int, int>> addList;
    //分别迭代
    while (it1 != l1.end() && it2 != l2.end()) {
        //如果第一个多项式的指数大于第二个多项式的指数，那么说明第一个无法再相加，进而it1++，但先把结果加到addList
        if (it1->second > it2->second) {
            addList.emplace_back(it1->first, it1->second);
            it1++;
        } //如果第一个多项式的指数小于第二个多项式的指数，那么说明第二个无法再相加，进而it2++，但先把结果加到addList
        else if (it1->second < it2->second) {
            addList.emplace_back(it2->first, it2->second);
            it2++;
        } //否则会有两种情况：一是两个指数相等；或者两个系数相加等于0
        else {
            //系数相加为0，跳过该情况
            if (it1->first + it2->first == 0) {
                it1++;
                it2++;
                continue;
            }
            //不然就把相加的结果加进去
            addList.emplace_back(it1->first + it2->first, it1->second);
            it1++;
            it2++;
        }
    }
    //把剩余的有序整数对加入
    while (it1 != l1.end()) {
        addList.emplace_back(it1->first, it1->second);
        it1++;
    }
    while (it2 != l2.end()) {
        addList.emplace_back(it2->first, it2->second);
        it2++;
    }
    /****加法实现****/
    return addList;
}

list<pair<int, int>> times(list<pair<int, int>> l1, list<pair<int, int>> l2) {
    /****乘法实现****/
    auto it1 = l1.begin(), it2 = l2.begin();
    list<pair<int, int>> timesList, temp;
    for (it1 = l1.begin(); it1 != l1.end(); it1++) {
        for (it2 = l2.begin(); it2 != l2.end(); it2++) {
            temp.emplace_back(it1->first * it2->first, it1->second + it2->second);
        }
        //每次相乘就是一个多项式，那么含n项的多项式就要加n次，故调用add方法
        timesList = add(temp, timesList);
        //加完之后要清空temp，因为之后的相乘结果不包括前面的（但timesList包括！）
        temp.clear();
    }
    /****乘法实现****/
    return timesList;
}

int main() {
    int n, m;
    cin >> n;
    list<pair<int, int>> l1, l2, addList, timesList;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        l1.emplace_back(first, second);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int first, second;
        cin >> first >> second;
        l2.emplace_back(first, second);
    }

    addList = add(l1, l2);
    timesList = times(l1, l2);
    //乘法要按照指数形式排序
    vector<pair<int, int>> v(timesList.begin(), timesList.end());
    sort(v.begin(), v.end(), cmp);

    if (v.empty()) cout << "0 0" << endl;
    else {
        for (auto it = v.begin(); it != v.end(); it++) {
            if (it != v.begin()) cout << " ";
            cout << it->first << " " << it->second;
        }
        cout << endl;
    }

    if (addList.empty()) cout << "0 0" << endl;
    else {
        for (auto it = addList.begin(); it != addList.end(); it++) {
            if (it != addList.begin()) cout << " ";
            cout << it->first << " " << it->second;
        }
        cout << endl;
    }

}
