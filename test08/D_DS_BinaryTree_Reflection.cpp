//
// Created by inver on 2021/10/28.
//


#include <iostream>

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
    int pos, pos1;
    string strTree;

    BiTreeNode *CreateBiTree();

    void PreOrder(BiTreeNode *t);

    void InOrder(BiTreeNode *t);

    void PostOrder(BiTreeNode *t);

    void Reflection(BiTreeNode *t);

    void FloorOrder(BiTreeNode *t);

public:
    BiTree() {};

    ~BiTree() {};

    void CreateTree(string TreeArray);

    void PreOrder();

    void InOrder();

    void PostOrder();

    void Reflection();

    void FloorOrder();
};

void BiTree::CreateTree(string TreeArray) {
    pos = 0;
    pos1 = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}

BiTreeNode *BiTree::CreateBiTree() {
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if (ch == '#')
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
    cout << t->data << ' ';
    PreOrder(t->LeftChild);
    PreOrder(t->RightChild);
}

void BiTree::Reflection() {
    Reflection(Root);
}

void BiTree::InOrder() {
    InOrder(Root);
}

void BiTree::InOrder(BiTreeNode *t) {
    if (t == nullptr) return;
    InOrder(t->LeftChild);
    cout << t->data << ' ';
    InOrder(t->RightChild);
}

void BiTree::PostOrder() {
    PostOrder(Root);
}

void BiTree::PostOrder(BiTreeNode *t) {
    if (t == nullptr) return;
    PostOrder(t->LeftChild);
    PostOrder(t->RightChild);
    cout << t->data << ' ';
}

void BiTree::Reflection(BiTreeNode *t) {
    if (t == nullptr || (t->RightChild == nullptr && t->LeftChild == nullptr)) return;
    if (t->RightChild != nullptr || t->LeftChild != nullptr) {
        BiTreeNode *temp = t->RightChild;
        t->RightChild = t->LeftChild;
        t->LeftChild = temp;
    }
    Reflection(t->LeftChild);
    Reflection(t->RightChild);
}

void BiTree::FloorOrder() {
    FloorOrder(Root);
}

//层序遍历的数组实现方法
void BiTree::FloorOrder(BiTreeNode *t) {
    //存储结点指针的数组，初始化为nullptr
    BiTreeNode *arr[100] = {nullptr};
    //i，j用来表示结点的关系，当i>j时循环
    int i = 0, j = 0;
    arr[i++] = t;   //根结点先进入数组
    while (i > j) {
        //如果j下标的结点是空的，那么就到右边的分支来遍历，即一直j++，直到不出现nullptr的情况
        if (arr[j] != nullptr) {
            cout << arr[j]->data << ' ';
            //保存结点的左孩子和右孩子，在数组上是靠在一起的
            arr[i++] = arr[j]->LeftChild;
            arr[i++] = arr[j]->RightChild;
        }
        j++;
    }
    //最终获得的数组，是我们的顺序存储二叉树数组！
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        int n;
        cin >> str;
        if (str == "#") {
            cout << "NULL" << endl << "NULL" << endl << "NULL" << endl << "NULL" << endl;
            continue;
        }
        BiTree tree;
        tree.CreateTree(str);
        tree.Reflection();
        tree.PreOrder();
        cout << endl;
        tree.InOrder();
        cout << endl;
        tree.PostOrder();
        cout << endl;
        tree.FloorOrder();
        cout << endl;
    }
}
