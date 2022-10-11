//
// Created by inver on 2021/12/2.
//

#include <iostream>

using namespace std;

static int cnt = 0;

class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode *leftChild;
    BinaryTreeNode *rightChild;
};

class BinaryTree {
public:
    int nodeNums = 0;
    BinaryTreeNode *root = nullptr;

    //用序列创建排序树
    void CreateTree() {
        cin >> nodeNums;
        for (int i = 0; i < nodeNums; i++) {
            int data;
            cin >> data;
            InsertNode(&root, data);
        }
    }

    //查找
    bool SearchNode(BinaryTreeNode *T, int key, BinaryTreeNode *f, BinaryTreeNode **P) {
        //如果T为空，那么说明查找失败，此时f为T的双亲，返回给P
        if (!T) {
            *P = f;
            return false;
        }
        //如果找到了，那么就让P指向T，即当前关键词的结点
        if (key == T->data) {
            *P = T;
            return true;
        }
            //否则没找到，分大小分别从左右子树查找，注意此时f应该传T，因为要表示出双亲
        else if (key < T->data) return SearchNode(T->leftChild, key, T, P);
        else return SearchNode(T->rightChild, key, T, P);
        //一旦这个函数结束运行，f就是T的双亲，P可能为双亲也有可能就是T
    }

    //函数重载
    bool SearchNode(BinaryTreeNode *T, int key) {
        cnt++;
        if (!T) {
            cnt = -1;
            return false;
        }
        if (key == T->data) {
            return true;
        } else if (key < T->data) return SearchNode(T->leftChild, key);
        else return SearchNode(T->rightChild, key);
    }

    //插入
    bool InsertNode(BinaryTreeNode **T, int key) {
        BinaryTreeNode *p;
        //如果找不到，那么插入
        if (!SearchNode(*T, key, nullptr, &p)) {
            //此时p为T的双亲
            auto *s = new BinaryTreeNode;
            s->data = key;
            s->leftChild = s->rightChild = nullptr;
            //如果p为空，那么T就是根结点
            if (!p) *T = s;
                //如果该节点的关键词小于双亲，那么双亲的左孩子就是新建的结点
            else if (key < p->data) p->leftChild = s;
                //否则就是右孩子
            else p->rightChild = s;
            return true;
        } else return false;
    }

    void InOrder(BinaryTreeNode *T) {
        if (!T) return;
        InOrder(T->leftChild);
        cout << T->data << ' ';
        InOrder(T->rightChild);
    }
};

int main() {
    int t, q, key;
    cin >> t;
    while (t--) {
        BinaryTree tree;
        tree.CreateTree();
        tree.InOrder(tree.root);
        cout << endl;
        cin >> q;
        while (q--) {
            cin >> key;
            tree.SearchNode(tree.root, key);
            cout << cnt << endl;
            cnt = 0;
        }
    }
}