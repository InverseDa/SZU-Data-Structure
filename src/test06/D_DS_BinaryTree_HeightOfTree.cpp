//
// Created by inver on 2021/10/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
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
    int pos;
    string strTree;

    BiTreeNode *CreateBiTree();

    void PreOrder(BiTreeNode *t);

    void InOrder(BiTreeNode *t);

    void PostOrder(BiTreeNode *t);

    int height(BiTreeNode *t);

public:
    BiTree() {};

    ~BiTree() {};

    void CreateTree(string TreeArray);

    void PreOrder();

    void InOrder();

    void PostOrder();

    int height();
};

void BiTree::CreateTree(string TreeArray) {
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}

BiTreeNode *BiTree::CreateBiTree() {
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if (ch == '0')
        T = nullptr;
    else {
        T = new BiTreeNode();
        T->data = ch;
        T->LeftChild = CreateBiTree();
        T->RightChild = CreateBiTree();
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

int BiTree::height(BiTreeNode *t) {
    if (t == nullptr) return 0;
    int LeftHeight = height(t->LeftChild);
    int RightHeight = height(t->RightChild);
    return max(LeftHeight, RightHeight) + 1;
}

int BiTree::height() {
    return height(Root);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        BiTree tree;
        tree.CreateTree(str);
        cout << tree.height() << endl;
    }
}
