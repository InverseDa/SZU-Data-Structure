//
// Created by inver on 2021/10/28.
//

#include <iostream>
#include <vector>

using namespace std;

//问题的两个结点
vector<pair<char, int>> number;

class TreeNode {
public:
    char data;
    //孩子数组
    vector<TreeNode *> child;

    TreeNode();
};

TreeNode::TreeNode() {
    child.resize(2, nullptr);
}

TreeNode *now;
bool flag = false;

class Tree {
private:
    string tempStr;
    int pos;

    //私有建树
    TreeNode *createTree();

public:
    TreeNode *root;
    TreeNode *next;

    //公有建树
    void *createTree(TreeNode *T, string str);

    //给值，找到结点
    void findNode(TreeNode *T, char ch);

    //判断树是否为空
    bool isEmpty();

    //判断两个结点是否为亲戚
    void isParent(TreeNode *T, char ch);

    //合成结点（用于建立亲戚树）
    void findNodeAndCombine(TreeNode *T, char ch);

    //计算深度
    void calculateDeep(TreeNode *t, char ch, int height);
};

bool Tree::isEmpty() {
    return root == nullptr;
}

void *Tree::createTree(TreeNode *T, string str) {
    //字符串变成"AA##A##"，这是为了建树
    tempStr = str.substr(0, 2) + "##" + str.substr(2) + "##";
    pos = 0;
    //如果是根结点，那从头开始建树
    if (T == root) root = createTree();
    else {
        //否则先把结果暂存到next
        next = createTree();
        //然后和next合并成一棵树
        findNodeAndCombine(root, str[0]);
    }
}

//如果找到了，那么就把结点给now
void Tree::findNode(TreeNode *T, char ch) {
    if (isEmpty() || T == nullptr) return;
    if (T->data == ch) {
        now = T;
        return;
    };
    findNode(T->child[0], ch);
    findNode(T->child[1], ch);
}

//树的合并
void Tree::findNodeAndCombine(TreeNode *T, char ch) {
    if (isEmpty() || T == nullptr) return;
    if (T->data == ch) {
        //进行合并
        T->child = next->child;
        return;
    }
    findNodeAndCombine(T->child[0], ch);
    findNodeAndCombine(T->child[1], ch);
}

//私有建树（差不多是老方法）
TreeNode *Tree::createTree() {
    char c = tempStr[pos++];
    if (c == '#') return nullptr;
    TreeNode *p = new TreeNode;
    p->data = c;
    p->child[0] = createTree();
    p->child[1] = createTree();
    return p;
}

//计算问题中两个结点的深度
void Tree::calculateDeep(TreeNode *t, char ch, int height) {
    if (t == nullptr) return;
    if (t->data == ch) number.push_back({ch, height});
    calculateDeep(t->child[0], ch, height + 1);
    calculateDeep(t->child[1], ch, height + 1);
}

//判断是否为亲戚的条件就是，找这个结点的一系列孩子是否有另外一个结点，有的话就是亲戚，flag为暂存布尔值（因为最后依据是 flag1 || flag2）
void Tree::isParent(TreeNode *T, char ch) {
    if (T == nullptr) return;
    if (T->data == ch) flag = true;
    isParent(T->child[0], ch);
    isParent(T->child[1], ch);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (!n && !m) break;
        Tree tree;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            //i==0，直接从根结点建树
            if (i == 0) tree.createTree(tree.root, str);
            else {
                //先找到字符串第一个位置的值
                tree.findNode(tree.root, str[0]);
                tree.createTree(now, str);
            }
        }
        //问题输入
        for (int i = 0; i < m; i++) {
            string str;
            bool f1, f2;
            cin >> str;
            //搜索两个结点的深度
            tree.calculateDeep(tree.root, str[0], 0);
            tree.calculateDeep(tree.root, str[1], 0);
            //判断第一个结点是否有亲戚（往上搜索）
            tree.findNode(tree.root, str[1]);
            tree.isParent(now, str[0]);
            f1 = flag;
            //判断第二个结点是否有亲戚（往上搜索）
            tree.findNode(tree.root, str[0]);
            tree.isParent(now, str[1]);
            //f2就是判断亲戚的关键
            f2 = f1 || flag;
            //不是亲戚
            if (!f2) cout << "-" << endl;
            else {
                //长辈输出parent
                if (number[0].second > number[1].second) {
                    int delta = abs(number[0].second - number[1].second);
                    if (delta == 1) cout << "parent" << endl;
                    if (delta == 2) cout << "grandparent" << endl;
                    if (delta > 2) {
                        for (int j = 0; j < delta - 2; j++) cout << "great-";
                        cout << "grandparent" << endl;
                    }
                }//晚辈输出child
                else {
                    int delta = abs(number[0].second - number[1].second);
                    if (delta == 1) cout << "child" << endl;
                    if (delta == 2) cout << "grandchild" << endl;
                    if (delta > 2) {
                        for (int j = 0; j < delta - 2; j++) cout << "great-";
                        cout << "grandchild" << endl;
                    }
                }
            }
            //重置
            flag = false;
            number.clear();
        }
    }
}
