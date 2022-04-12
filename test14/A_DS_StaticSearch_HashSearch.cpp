//
// Created by inver on 2021/12/9.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;
//哈希表
class Hash {
public:
    //哈希链表，链地址法
    vector<list<int>> HashList;
    //初始化哈希链表
    Hash(int n) {
        HashList.resize(2 * n);
    }
    //获取哈希值
    int getHash(int key) {
        return key % 11;
    }
    //添加元素
    void addElement(int key) {
        int hash = getHash(key);
        for (auto &it : HashList[hash]) {
            if (it == key) {
                //说明本就存在，返回
                return;
            }
        }
        //否则添加元素，表头插入法
        HashList[hash].push_front(key);
    }
    //查找
    void Search(int key) {
        int hash = getHash(key), cnt = 0;
        for (auto &it : HashList[hash]) {
            //查找次数
            cnt++;
            if (it == key) {
                //输出
                cout << hash << ' ' << cnt << endl;
                return;
            }
        }
        //否则没找到，输出error并加入元素
        cout << "error" << endl;
        addElement(key);
    }
};

int main() {
    int n;
    cin >> n;
    Hash myHash(n);
    while (n--) {
        int value;
        cin >> value;
        myHash.addElement(value);
    }
    cin >> n;
    while (n--) {
        int val;
        cin >> val;
        myHash.Search(val);
    }
}