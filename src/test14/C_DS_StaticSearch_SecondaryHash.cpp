//
// Created by inver on 2021/12/9.
//

#include <iostream>

using namespace std;

//哈希表
class Hash {
public:
    //element哈希数组，array原序列
    int hashMap[100];
    int elementSize, hashMapSize, k = 0;

    //初始化，所有哈希数组的值都为-1
    Hash(int m, int n) {
        hashMapSize = m;
        elementSize = n;
        /**hashMap = new int[hashMapSize];**/
        for (int i = 0; i < hashMapSize; i++)
            hashMap[i] = -1;
    }

    //获取哈希值
    int getHash(int key) {
        return key % 11;
    }

    //添加元素
    void addElement(int key) {
        int hash = getHash(key), d = 1, p = 1;
        //二次探测再哈希法
        while (hashMap[hash] != -1) {
            hash = (key % 11 + p * d * d) % hashMapSize;
            if (hash < 0) hash = hashMapSize + hash;
            p = -1 * p;
            if (p == 1) d++;
        }
        hashMap[hash] = key;
    }

    void Search(int key) {
        int hash = getHash(key), cnt = 0, d = 0, p = 1;
        //如果此时不等于，那么就再哈希，直到找到或者找不到
        while (true) {
            cnt++;
            hash = (key % 11 + p * d * d) % hashMapSize;
            if (hash < 0) hash += hashMapSize;
            if (hashMap[hash] == key) {
                cout << "1 " << cnt << " " << hash + 1 << endl;
                break;
            } else if (hashMap[hash] == -1) {
                cout << "0 " << cnt << endl;
                break;
            } else {
                if (cnt % 2 == 0) p *= -1;
                else d++;
            }
        }
    }

    void PrintHashMap() {
        for (int i = 0; i < hashMapSize; i++) {
            if (i != 0) cout << ' ';
            if (hashMap[i] == -1) cout << "NULL";
            else cout << hashMap[i];
        }
        cout << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        Hash myHash(m, n);
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            myHash.addElement(val);
        }
        int p;
        cin >> p;
        myHash.PrintHashMap();
        while (p--) {
            cin >> val;
            myHash.Search(val);
        }
    }
}