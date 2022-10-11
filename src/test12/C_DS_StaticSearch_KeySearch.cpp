//
// Created by inver on 2021/11/25.
//

#include <iostream>
#include <vector>

using namespace std;

int temp = 1;

class SequentialSearchTable {
public:
    int *elem, *maxKey;
    vector<vector<int>> matrix;
    int length, maxKeyLen;

    void create() {
        cin >> length;
        elem = new int[length + 1];
        //从1开始
        for (int i = 1; i <= length; i++) {
            cin >> elem[i];
        }
    }

    void pushMaxKey() {
        cin >> maxKeyLen;
        maxKey = new int[maxKeyLen];
        matrix.resize(maxKeyLen);
        for (int i = 0; i < maxKeyLen; i++) {
            cin >> maxKey[i];
        }
    }

    void fenKuai() {
        int i = 1;
        for (int k = 0; k < maxKeyLen - 1 && i < length + 1; i++) {
            if (maxKey[k] < elem[i]) {
                k++;
                temp++;
            }
            matrix[k].push_back(elem[i]);
        }
        for (i; i < length + 1; i++)
            matrix[maxKeyLen - 1].push_back(elem[i]);
    }

    void destroy() {
        delete[] elem;
        delete[] maxKey;
    }

    int search(int key) {
        int i = 0, preLen = 0;
        for (i; key > maxKey[i]; i++) {
            temp++;
            preLen += matrix[i].size();
            if (i == maxKeyLen - 1 && key > maxKey[i]) return 0;
        }
        for (int j = 0; j < matrix[i].size(); j++) {
            temp++;
            if (matrix[i][j] == key && i == 0) {
                return j + 1;
            } else if (matrix[i][j] == key && i != 0) {
                return preLen + j + 1;
            }
        }
        return 0;
    }
};

int main() {
    SequentialSearchTable SST;
    SST.create();
    SST.pushMaxKey();
    SST.fenKuai();
    int t;
    cin >> t;
    while (t--) {
        temp = 1;
        int value;
        cin >> value;
        int pos = SST.search(value);
        if (!pos) cout << "error" << endl;
        else cout << pos << "-" << temp << endl;
    }
}