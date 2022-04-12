//
// Created by inver on 2021/11/25.
//

#include <iostream>

using namespace std;

class SequentialSearchTable {
public:
    int *elem;
    int length;

    void create() {
        cin >> length;
        elem = new int[length + 1];
        //从1开始
        for (int i = 1; i <= length; i++) {
            cin >> elem[i];
        }
    }

    void destroy() {
        delete[] elem;
    }

    //二分查找，折半查找
    int binarySearch(int key) {
        //low指针在第一位，high指针在最后一位
        int low = 1, high = length;
        while (low <= high) {
            //mid指针在中间
            int mid = (low + high) / 2;
            if (elem[mid] == key) return mid;
                //如果mid元素比key小，说明区间在后面，就令下界low等于mid的后一位
            else if (elem[mid] < key) low = mid + 1;
                //否则就是mid元素大，说明区间在前面
            else high = mid - 1;
        }
        return 0;
    }
};

int main() {
    SequentialSearchTable SST;
    SST.create();
    int t;
    cin >> t;
    while (t--) {
        int key;
        cin >> key;
        int pos = SST.binarySearch(key);
        if (!pos) cout << "error" << endl;
        else cout << pos << endl;
    }
}