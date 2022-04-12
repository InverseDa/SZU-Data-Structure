//
// Created by inver on 2021/12/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    char data;
    int lchild, rchild;

    Node(char ch, char lchild, char rchild) {
        data = ch;
        if (lchild != '-') this->lchild = lchild - '0';
        else this->lchild = -1;

        if (rchild != '-') this->rchild = rchild - '0';
        else this->rchild = -1;
    }
};

class Tree {
public:
    int num;
    vector<Node *> TreeArray;

    Tree(int n) {
        num = n;
        TreeArray.resize(n);
    }

    void insert(int pos, char ch, char lchild, char rchild) {
        TreeArray[pos] = new Node(ch, lchild, rchild);
    }

};

int main() {
    int n;
    cin >> n;
    Tree t1(n);
    for (int i = 0; i < n; i++) {
        char ch, lchild, rchild;
        cin >> ch >> lchild >> rchild;
        t1.insert(i, ch, lchild, rchild);
    }
    cin >> n;
    Tree t2(n);
    for (int i = 0; i < n; i++) {
        char ch, lchild, rchild;
        cin >> ch >> lchild >> rchild;
        t2.insert(i, ch, lchild, rchild);
    }
    cin.get();

}
