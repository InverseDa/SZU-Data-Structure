//
// Created by inver on 2021/10/30.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//结点之间距离排序比较器
bool cmp(pair<pair<char, char>, int> a, pair<pair<char, char>, int> b) {
    return a.second > b.second;
}

class BiNode {
public:
    BiNode *leftChild, *rightChild;
    char data;
};

class BiTree {
public:
    BiNode *root;
    string strTree;
    int pos, len = 0, flag = 0;
    //所有的叶子和根结点，包括两个元素：{结点值，到根结点的距离}，类型（0为左子树叶子，1为右子树叶子，2为根结点）
    vector<pair<pair<char, int>, int>> leaveAndRootNode;
    //所有叶子和根结点的距离，两个元素：{两个结点值}，距离
    vector<pair<pair<char, char>, int>> maxNode;

    BiTree();

    void createTree(string str);

    //计算深度，这里可以计算每个节点的深度
    void calculateDeep(BiNode *T, int height);

    //计算maxNode数组
    void calculateMax();

private:
    BiNode *createTree();
};

BiTree::BiTree() {
    pos = 0;
}

void BiTree::createTree(string str) {
    strTree.append(str);
    root = createTree();
}

BiNode *BiTree::createTree() {
    char c = strTree[pos++];
    if (c == '#') return nullptr;
    BiNode *p = new BiNode;
    p->data = c;
    p->leftChild = createTree();
    p->rightChild = createTree();
    return p;
}

//计算深度，这里可以计算每个节点的深度
void BiTree::calculateDeep(BiNode *T, int height) {
    if (T == nullptr) return;
    //如果是叶子且是左子树的叶子
    if (!T->leftChild && !T->rightChild && flag == 0) {
        leaveAndRootNode.push_back({{T->data, height}, 0});//进入leaveAndRootNode数组
        return;
    } //如果是叶子且是右子树的叶子
    else if (!T->leftChild && !T->rightChild && flag == 1) {
        leaveAndRootNode.push_back({{T->data, height}, 1});//进入leaveAndRootNode数组
        return;
    }
    calculateDeep(T->leftChild, height + 1);
    //如果是根结点（中序原理），那么进入数组，并设flag=1
    if (T == root) {
        flag = 1;
        leaveAndRootNode.push_back({{T->data, 0}, 2});
    }
    calculateDeep(T->rightChild, height + 1);
}

//计算maxNode数组
void BiTree::calculateMax() {
    //如果leaveAndRootNode数组只有两个元素，那么其中一个必定是根结点
    for (int i = 0; i < leaveAndRootNode.size(); i++) {
        for (int j = i + 1; j < leaveAndRootNode.size(); j++) {
            //second是类型，相同说明两个结点在同一颗子树里，那么就两个距离相加-2（画图可得）；不相同就说明在不同子树，或者其中一个是根结点，直接相加就行
            if (leaveAndRootNode[i].second == leaveAndRootNode[j].second) {
                maxNode.push_back({{leaveAndRootNode[i].first.first, leaveAndRootNode[j].first.first},
                                   leaveAndRootNode[i].first.second + leaveAndRootNode[j].first.second - 2});
            } else if (leaveAndRootNode[i].second != leaveAndRootNode[j].second) {
                maxNode.push_back({{leaveAndRootNode[i].first.first, leaveAndRootNode[j].first.first},
                                   leaveAndRootNode[i].first.second + leaveAndRootNode[j].first.second});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        BiTree tree;
        string str;
        cin >> str;
        tree.createTree(str);
        tree.calculateDeep(tree.root, 0);
        tree.calculateMax();
        sort(tree.maxNode.begin(), tree.maxNode.end(), cmp);
        //如果maxNode是空的，那么输出0
        if (tree.maxNode.empty())
            cout << 0 << ":" << endl;
        else
            cout << tree.maxNode[0].second << ":" << tree.maxNode[0].first.first << " " << tree.maxNode[0].first.second
                 << endl;
    }
}