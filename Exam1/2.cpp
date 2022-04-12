//
// Created by inver on 2021/12/23.
// 火车调度问题

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        stack<char> s;
        string final, order, popOrder;
        int n, k = 0;
        cin >> n;
        //输入进站序列，出栈序列
        cin >> order >> popOrder;
        //模拟进站出站的过程
        for (int i = 0; i < order.size(); i++){
            //初始为空栈，这时候根据进站序列，进入栈
            s.push(order[i]);
            final += "in\n";
            //每次都判断栈顶元素是否为出战序列的第k个（k从0开始），如果是，这个时候就应该出栈，然后k++
            while (!s.empty() && s.top() == popOrder[k]) {
                s.pop();
                final += "out\n";
                k++;
            }
        }
        //如果最后栈没有空，且k不等于出站序列的长度，那么就说明这个出站序列是错的
        if (!s.empty() && k != popOrder.size()) cout << "No" << endl;
        else cout << "Yes\n" << final;
        cout << "FINISH" << endl;
    }
}