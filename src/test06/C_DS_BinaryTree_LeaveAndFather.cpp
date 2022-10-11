//
// Created by inver on 2021/10/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<char> father;
vector<char> leave;
vector<char> leaveOfFather;
int cnt = 0;

class BiTreeNode {
public:
    char data;
    char father;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;

    BiTreeNode() : LeftChild(NULL), RightChild(NULL) {};

    ~BiTreeNode() {};
};

class BiTree {
private:
    BiTreeNode *Root;
    int pos;
    int leaveCnt = 0;
    string strTree;

    BiTreeNode *CreateBiTree();

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

    int getLeaveCnt() const;
};

void BiTree::CreateTree(string TreeArray) {
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}

BiTreeNode *BiTree::CreateBiTree() {
    BiTreeNode *T, *P;
    char ch;
    ch = strTree[pos++];
    if (ch == '0') {
        T = nullptr;
    } else {
        T = new BiTreeNode();
        T->data = ch;
        father.push(ch);
        if (cnt++ != 0) {
            T->father = father.front();
            father.pop();
        }
        T->LeftChild = CreateBiTree();
        T->RightChild = CreateBiTree();
        father.pop();
        father.push(strTree[0]);
    }
    return T;
}

void BiTree::PreOrder() {
    PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode *t) {
    if (t == nullptr) return;
    //cout << t->data;
    if (t->LeftChild == nullptr && t->RightChild == nullptr) {
        leave.push_back(t->data);
        leaveOfFather.push_back(t->father);
    }
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

int BiTree::getLeaveCnt() const {
    return leaveCnt;
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
        for (auto i : leave)
            cout << i << ' ';
        cout << endl;
        for (auto i : leaveOfFather)
            cout << i << ' ';
        cout << endl;
        leave.clear();
        leaveOfFather.clear();
    }
}
