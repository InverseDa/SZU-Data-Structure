//
// Created by inver on 2021/10/14.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BiTreeNode {
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;

    BiTreeNode() : LeftChild(NULL), RightChild(NULL) {};

    ~BiTreeNode() {};
};

class BiTree {
private:
    BiTreeNode *Root;
    int pos, len;
    string strTree;

    BiTreeNode *CreateBiTree(int p);

    void PreOrder(BiTreeNode *t);

    void InOrder(BiTreeNode *t);

    void PostOrder(BiTreeNode *t);

public:
    BiTree() {};

    ~BiTree() {};

    void CreateTree(string TreeArray);

    void PreOrder();

    void InOrder();

    void PostOrder();
};

void BiTree::CreateTree(string TreeArray) {
    pos = 0;
    len = TreeArray.size();
    strTree.assign(TreeArray);
    Root = CreateBiTree(pos + 1);
}

BiTreeNode *BiTree::CreateBiTree(int p) {
    BiTreeNode *T;
    char ch;
    ch = strTree[p - 1];
    if (p > len) return nullptr;
    if (ch == '0')
        T = nullptr;
    else {
        T = new BiTreeNode();
        T->data = ch;
        T->LeftChild = CreateBiTree(2 * p);
        T->RightChild = CreateBiTree(2 * p + 1);
    }
    return T;
}

void BiTree::PreOrder() {
    PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode *t) {
    if (t == nullptr) return;
    cout << t->data;
    PreOrder(t->LeftChild);
    PreOrder(t->RightChild);
}

void BiTree::InOrder() {
    InOrder(Root);
}

void BiTree::InOrder(BiTreeNode *t) {
    if (t == nullptr) return;
    InOrder(t->LeftChild);
    cout << t->data;
    InOrder(t->RightChild);
}

void BiTree::PostOrder() {
    PostOrder(Root);
}

void BiTree::PostOrder(BiTreeNode *t) {
    if (t == nullptr) return;
    PostOrder(t->LeftChild);
    PostOrder(t->RightChild);
    cout << t->data;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        BiTree tree;
        tree.CreateTree(str);
        tree.PreOrder();
        printf("\n");
    }
}
