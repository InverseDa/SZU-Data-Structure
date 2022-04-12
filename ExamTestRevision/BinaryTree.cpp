//
// Created by inver on 2021/12/22.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node *rchild, *lchild;
    char data, father;
};

class Tree {
public:
    Node *root;
    int index = 0;
    vector<int> arr;
    string str;

    //同时记录了父亲
    void createTree(Node *&t, char f) {
        char data = str[index++];
        if (data == '0') {
            t = nullptr;
            return;
        }
        t = new Node;
        t->data = data;
        t->father = f;
        createTree(t->lchild, t->data);
        createTree(t->rchild, t->data);
    }

    void createTree(Node *&t, char f, int index) {
        if (arr[index] == '0' && index >= arr.size()) {
            t = nullptr;
            return;
        }
        t = new Node;
        t->data = arr[index];
        t->father = f;
        createTree(t->lchild, t->data, 2 * index);
        createTree(t->rchild, t->data, 2 * index + 1);
    }

    void preOrder(Node *t) {
        if (t == nullptr) return;
        cout << t->data << " ";
        preOrder(t->lchild);
        preOrder(t->rchild);
    }

    void inOrder(Node *t) {
        if (t == nullptr) return;
        inOrder(t->lchild);
        cout << t->data << " ";
        inOrder(t->rchild);
    }

    void postOrder(Node *t) {
        if (t == nullptr) return;
        postOrder(t->lchild);
        postOrder(t->rchild);
        cout << t->data << " ";
    }

    int heightOfTree(Node *t) {
        if (t == nullptr) return 0;
        int lheight = heightOfTree(t->lchild);
        int rheight = heightOfTree(t->rchild);
        return max(lheight, rheight) + 1;
    }

    bool isSame(Node *p, Node *q) {
        if (p == nullptr && q == nullptr) return true;
        if (!p || !q) return false;
        if (p->data != q->data) return false;
        return isSame(p->lchild, q->lchild) && isSame(p->rchild, q->rchild);
    }

};

int main() {
    string str;
    Tree tree;
    cin >> str;
    tree.str = str;
    tree.createTree(tree.root, '0');
    tree.preOrder(tree.root);
    cout << tree.heightOfTree(tree.root);
}
