//
// Created by inver on 2021/10/22.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>

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
    string strTree;

    BiNode *CreateTreeInPreWay();

    void PreOrder(BiNode *T);

public:
    int pos, wpl_pos, wplBian, wpl;
    vector<int> aplArray;

    BiTree() {};

    ~BiTree() {};

    void CreateTree(string TreeArray, vector<int> aplarray, int n);

    void PreOrder();

};

void BiTree::CreateTree(string TreeArray, vector<int> aplarray, int n) {
    pos = wpl_pos = wplBian = wpl = 0;
    strTree.assign(TreeArray);
    aplArray.resize(n);
    for (int i = 0; i < n; i++) aplArray[i] = aplarray[i];
    Root = CreateTreeInPreWay();
}

BiNode *BiTree::CreateTreeInPreWay() {
    BiNode *T;
    char ch;
    ch = strTree[pos++];
    if (ch == '0')
        T = nullptr;
    else {
        T = new BiNode();
        T->data = ch;
        T->leftChild = CreateTreeInPreWay();
        T->rightChild = CreateTreeInPreWay();
    }
    return T;
}

void BiTree::PreOrder() {
    PreOrder(Root);
}

void BiTree::PreOrder(BiNode *T) {
    if (T == nullptr) return;
    if (isupper(T->data)) {
        wpl += aplArray[wpl_pos++] * wplBian;
    }
    if (T->leftChild != nullptr || T->rightChild != nullptr) wplBian++;
    PreOrder(T->leftChild);
    if (T == Root) wplBian = 1;
    PreOrder(T->rightChild);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        int apl_num;
        cin >> str;
        cin >> apl_num;
        vector<int> apl(apl_num);
        for (int i = 0; i < apl_num; i++) cin >> apl[i];
        BiTree tree;
        tree.CreateTree(str, apl, apl_num);
        tree.PreOrder();
        cout << tree.wpl << endl;
    }
}