//
// Created by inver on 2021/10/28.
//

#include <iostream>
#include <vector>

using namespace std;

class BiTreeNode {
public:
    //二叉树的孩子表示法，左孩子和左孩子的兄弟（也就是右孩子）
    BiTreeNode *leftChild, *rightChild;
    char data;

    BiTreeNode() : leftChild(nullptr), rightChild(nullptr) {};
};

class BiTree {
public:
    BiTreeNode *root;

    //二叉树森林转成二叉树
    void combineBinaryTree(int n, vector<BiTreeNode *> BiTreeArray);

    //叶子的编码
    void leaveCode(BiTreeNode *T, string st);

};

//二叉树森林转成二叉树，原理就是从第二课二叉树开始，每个二叉树的根结点都为前一个二叉树根结点的右孩子
void BiTree::combineBinaryTree(int n, vector<BiTreeNode *> BiTreeArray) {
    //从1开始
    for (int i = 1; i < n; i++) {
        BiTreeArray[i - 1]->rightChild = BiTreeArray[i];
    }
    //最后设置这颗树的根结点
    root = BiTreeArray[0];
}

//叶子编码，访问左孩子则为0，右孩子则为1，最后得到编码
void BiTree::leaveCode(BiTreeNode *T, string st) {
    if (T == nullptr) return;
    string str = st;
    //如果是叶子，输出编码
    if (!T->leftChild && !T->rightChild) {
        //因为输出要求是最后一位之后没有空格，所以依次输出到str.size-1
        for (int i = 0; i < str.size() - 1; i++) cout << str[i];
        cout << endl;
    }
    leaveCode(T->leftChild, str + "0 ");
    leaveCode(T->rightChild, str + "1 ");
}

class TreeNode {
public:
    //普通树的孩子表示，包括这个节点的指和孩子数组（它的孩子组成的数组）
    char data;
    vector<TreeNode *> child;

    //分支为B，该结点的孩子的个数就是分支的个数
    TreeNode(int B);
};

TreeNode::TreeNode(int B) {
    child.resize(B, nullptr);
}

class Tree {
public:
    TreeNode *root;
    string strTree;
    int B, pos = 0;

    //创建树
    void CreateTree(string str, int b);

    //树转成二叉树
    BiTreeNode *transToBinaryTree(TreeNode *T);

private:
    TreeNode *CreateTree();
};

void Tree::CreateTree(string str, int b) {
    //因为题中输入包含空格，所以转成无空格形式
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') continue;
        strTree.push_back(str[i]);
    }
    pos = 0;
    //设定分支
    this->B = b;
    //从根结点开始建树
    root = CreateTree();
}

TreeNode *Tree::CreateTree() {
    //0则说明结点空，返回空结点
    if (strTree[pos] == '0') {
        pos++;
        return nullptr;
    }
    //建立一个新结点
    TreeNode *temp = new TreeNode(B);
    temp->data = strTree[pos++];
    for (int i = 0; i < B; i++) {
        //新结点的孩子就是在数组位置的下一位啦！
        temp->child[i] = CreateTree();
    }
    return temp;
}

//神奇的转二叉树算法（这常人真的能想到吗。。。）原理就是我们手写的二叉树转化法：左孩子，右兄弟
BiTreeNode *Tree::transToBinaryTree(TreeNode *T) {
    if (T == nullptr) return nullptr;
    BiTreeNode *p = new BiTreeNode;
    p->data = T->data;
    //根结点不会涉及到右孩子！因为转成的二叉树的根结点是不存在右孩子的。
    p->leftChild = transToBinaryTree(T->child[0]);//从根的孩子入手，一直创左孩子，直到结点为空
    //如果p的左孩子不是空的，那么就创建p的左孩子的右孩子
    if (p->leftChild != nullptr) {
        //q是p的左孩子
        BiTreeNode *q = p->leftChild;
        for (int i = 1; i < B; i++) {
            //一直创建q的右孩子
            q->rightChild = transToBinaryTree(T->child[i]);
            if (q->rightChild != nullptr) q = q->rightChild;
        }
    }
    return p;
}

int main() {
    int n, b;
    cin >> n >> b;
    vector<Tree> tree(n);
    vector<BiTreeNode *> bitreenode(n);
    BiTree biTree;
    getchar();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        tree[i].CreateTree(str, b);
        bitreenode[i] = new BiTreeNode;
        bitreenode[i] = tree[i].transToBinaryTree(tree[i].root);
    }
    biTree.combineBinaryTree(n, bitreenode);
    biTree.leaveCode(biTree.root, "");
}