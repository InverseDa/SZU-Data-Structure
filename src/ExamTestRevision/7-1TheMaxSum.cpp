//
// Created by inver on 2021/12/12.
// 最大子列和问题

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, sum = 0, max = 0;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) {
        cin >> i;
    }
    /*
     * 思路是这样的：
     * sum记录当前的和数，max为最大和数
     * 遍历数组的元素，如果和大于max，那么就更新max值（这样下去当然最大的就是max了）
     * 如果最后sum=0，那么需要重新计算，所以sum = 0
     */
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }

    cout << max << endl;
}
