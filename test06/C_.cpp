#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<char> leave;
vector<char> leaveOfFather;

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

    BiTreeNode *CreateBiTree(BiTreeNode *P);

    void PreOrder(BiTreeNode *t);

public:
    BiTree() {};

    ~BiTree() {};

    void CreateTree(string TreeArray);

    void PreOrder();

    int getLeaveCnt() const;
};

void BiTree::CreateTree(string TreeArray) {
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree(nullptr);
}

BiTreeNode *BiTree::CreateBiTree(BiTreeNode *P) {
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if (ch == '0') {
        T = nullptr;
    } else {
        T = new BiTreeNode();
        T->data = ch;
        if(P!= nullptr) T->father = P->data;
        T->LeftChild = CreateBiTree(T);
        T->RightChild = CreateBiTree(T);
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
