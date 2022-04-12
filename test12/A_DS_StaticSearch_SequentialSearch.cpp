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

//带哨兵的顺序表查找
    int search(int key) {
        //作为哨兵
        elem[0] = key;
        int i = length;
        while (elem[i] != key)
            i--;
        return i;
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
        if (!SST.search(key)) cout << "error" << endl;
        else cout << SST.search(key) << endl;
    }
}