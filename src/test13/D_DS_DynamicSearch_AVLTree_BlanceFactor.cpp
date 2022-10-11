//
// Created by inver on 2021/12/2.
//

#include <iostream>

using namespace std;

class BinaryTreeNode {
public:
    char data;
    BinaryTreeNode *leftChild;
    BinaryTreeNode *rightChild;
};

class BinaryTree {
public:
    int nodeNums = 0;
    int lh = 0, rh = 0;
    BinaryTreeNode *root = nullptr;
    string NodeArray;
    int *hash;

    void initial() {
        int n;
        cin >> n;
        cin >> NodeArray;
        hash = new int[200];
    }
    //利用二叉树数组存储的构建方法建立二叉树
    BinaryTreeNode *CreateTree(BinaryTreeNode *&p, int k) {
        char data = NodeArray[k];
        if (data == '0' || data == '\000') return nullptr;
        p = new BinaryTreeNode;
        p->data = data;
        p->leftChild = CreateTree(p->leftChild, 2 * k + 1);
        p->rightChild = CreateTree(p->rightChild, 2 * k + 2);
        return p;
    }
    //计算树的高度
    int TreeHeight(BinaryTreeNode *p) {
        if (!p) return 0;
        int leftHeight = TreeHeight(p->leftChild);
        int rightHeight = TreeHeight(p->leftChild);
        return max(leftHeight,rightHeight) + 1;
    }
    //统计所有子树的高度，并且统计到hash数组中（先序遍历原理）
    void calculateHeight(BinaryTreeNode *p) {
        if (!p) return;
        //lh：结点的左子树高度、rh：结点的右子树高度
        lh = TreeHeight(p->leftChild);
        rh = TreeHeight(p->rightChild);
        //加入的hash中，为了便于查找
        hash[p->data] = lh - rh;
        //先序遍历
        calculateHeight(p->leftChild);
        calculateHeight(p->rightChild);
    }
    //最后后序遍历输出
    void PostOrder(BinaryTreeNode *p) {
        if (!p) return;
        PostOrder(p->leftChild);
        PostOrder(p->rightChild);
        cout << p->data << " " << hash[p->data] << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        BinaryTree tree;
        tree.initial();
        tree.CreateTree(tree.root, 0);
        tree.calculateHeight(tree.root);
        tree.PostOrder(tree.root);
    }
}