//
// Created by inver on 2021/10/21.
//

#include <iostream>
#include <string>

using namespace std;

class BiNode {
public:
    char data;
    BiNode *leftChild;
    BiNode *rightChild;

    BiNode() : leftChild(nullptr), rightChild(nullptr) {};

    ~BiNode() {};
};

class BiTree {
private:
    BiNode *Root;
    int pos, len;
    string strTree;

    BiNode *CreateTreeInPreWay();

    BiNode *CreateTreeInArrayWay(int p);

    bool isTheSameTree(BiNode *l, BiNode *r);

public:
    BiTree() {};

    ~BiTree() {};

    void CreateTree(string TreeArray, int mode);

    bool isTheSameTree(BiTree anotherTree);
};

void BiTree::CreateTree(string TreeArray, int mode) {
    pos = 0;
    len = TreeArray.size();
    strTree.assign(TreeArray);
    //0，先序创建；1，数组创建
    if (mode == 0) Root = CreateTreeInPreWay();
    else Root = CreateTreeInArrayWay(pos + 1);
}

BiNode *BiTree::CreateTreeInPreWay() {
    BiNode *T;
    char ch;
    ch = strTree[pos++];
    if (ch == '#' || pos > len)
        T = nullptr;
    else {
        T = new BiNode();
        T->data = ch;
        T->leftChild = CreateTreeInPreWay();
        T->rightChild = CreateTreeInPreWay();
    }
    return T;
}

BiNode *BiTree::CreateTreeInArrayWay(int p) {
    BiNode *T;
    char ch;
    ch = strTree[p - 1];
    if (p > len || ch == '#') return nullptr;
    T = new BiNode();
    T->data = ch;
    T->leftChild = CreateTreeInArrayWay(2 * p);
    T->rightChild = CreateTreeInArrayWay(2 * p + 1);
    return T;
}

bool BiTree::isTheSameTree(BiNode *l, BiNode *r) {
    if (l == nullptr && r == nullptr) return true;
    if (l == nullptr || r == nullptr) return false;
    if (l->data != r->data) return false;
    return isTheSameTree(l->leftChild, r->leftChild) && isTheSameTree(l->rightChild, r->rightChild);
}

bool BiTree::isTheSameTree(BiTree anotherTree) {
    return isTheSameTree(Root, anotherTree.Root);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        BiTree a, b;
        a.CreateTree(str1, 1);//array
        b.CreateTree(str2, 0);//pre
        if (a.isTheSameTree(b)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}