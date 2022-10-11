//
// Created by inver on 2021/10/28.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

class BiTreeNode {
public:
    char data;
    int w;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;

    BiTreeNode() : LeftChild(NULL), RightChild(NULL) {};

    ~BiTreeNode() {};
};

class BiTree {
private:
    BiTreeNode *Root;
    int pos, sum = 0, pos1 = 0;
    string strTree;
    vector<int> wt;

    BiTreeNode *CreateBiTree();

    void PreOrder(BiTreeNode *t);

public:
    BiTree() {};

    ~BiTree() {};

    void CreateTree(string TreeArray, vector<int> arr);

    void PreOrder();

};

void BiTree::CreateTree(string TreeArray, vector<int> arr) {
    pos = 0;
    strTree.assign(TreeArray);
    wt = move(arr);
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
        T->w = wt[pos1++];
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
    if (t->LeftChild == nullptr && t->RightChild == nullptr) {
        res.push_back(sum + t->w);
    } else sum += t->w;
    PreOrder(t->LeftChild);
    if (t == Root) sum = t->w;
    PreOrder(t->RightChild);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        int n;
        cin >> str;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        BiTree tree;
        tree.CreateTree(str, arr);
        tree.PreOrder();
        sort(res.begin(), res.end());
        cout << res[res.size() - 1] << endl;
        res.clear();
    }
}
