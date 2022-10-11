//
// Created by inver on 2021/10/21.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MaxW = 9999;

class HuffNode {
public:
    int weight; //权值
    char data;//数据
    int parent; //父节点下标
    int leftchild;  //左孩子下标
    int rightchild; //右孩子下标
};

//哈夫曼树
class HuffMan {
private:
    void MakeTree();

    //从1到pos的位置找到权值最小的节点，并记录到s1和s2
    void SelectMin(int pos, int *s1, int *s2);

public:
    int len;    //节点数量
    int lnum;   //叶子数量
    HuffNode *huffTree; //哈夫曼树的数组
    string *huffCode;   //每个字符对应的哈夫曼编码

    void MakeTree(int n, int wt[], char d[]);   //生成哈夫曼树

    void Coding();  //生成哈夫曼编码

    void Destroy(); //摧毁树

    int Decode(const string codestr, char txtstr[]);    //解码，即根据哈夫曼推出字符串
};

void HuffMan::MakeTree(int n, int wt[], char d[]) {
    lnum = n;   //n个叶子结点，就会有2n-1个节点
    len = 2 * n - 1;
    huffTree = new HuffNode[2 * n];     //哈夫曼树，用数组存储。因为从1开始，所以开2*n-1+1的空间
    huffCode = new string[lnum + 1];    //哈夫曼编码只需要叶子节点+1即可

    for (int i = 1; i <= n; i++) {
        huffTree[i].weight = wt[i - 1]; //每个哈夫曼节点都由权值和数据组成，数据是字符
        huffTree[i].data = d[i - 1];
    }
    for (int i = 1; i <= len; i++) {
        //初始化哈夫曼树，先把所有叶子节点的
        //这里的parent，leftchild和rightchild都是数组下标！这里一定要分清楚
        if (i > n) {
            huffTree[i].weight = 0;
            huffTree[i].data = '0';
        }
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree(); //进行节点合并
}

void HuffMan::SelectMin(int pos, int *s1, int *s2) {
    int w1, w2;
    w1 = w2 = MaxW;
    *s1 = *s2 = 0;
    for (int i = 1; i <= pos; i++) {
        //节点的parent为0说明没被访问过！
        //比较得到最小的两个节点，其实就是求最小值
        if (huffTree[i].parent == 0 && huffTree[i].weight < w1) {
            w2 = w1;
            w1 = huffTree[i].weight;
            *s2 = *s1;
            *s1 = i;
        } else if (huffTree[i].parent == 0 && huffTree[i].weight < w2) {
            w2 = huffTree[i].weight;
            *s2 = i;
        }
    }
}

void HuffMan::MakeTree() {
    int s1, s2;
    //从n+1开始，合并节点，也就是找到两个权值最小且没被访问的节点
    for (int i = lnum + 1; i <= len; i++) {
        SelectMin(i - 1, &s1, &s2); //找两个最小权值节点
        //找到后，给了s1和s2，故设置s1和s2的父节点为i
        huffTree[s1].parent = i;
        huffTree[s2].parent = i;
        //父节点的左右孩子设为s1和s2
        huffTree[i].leftchild = s1;
        huffTree[i].rightchild = s2;
        //父节点的权值为左右孩子之和
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
    }
}

void HuffMan::Destroy() {
    len = 0;
    lnum = 0;
    delete[] huffTree;
    delete[] huffCode;
}

void HuffMan::Coding() {
    char *cd;
    int c, f, start;
    cd = new char[lnum];
    cd[lnum - 1] = '\0';
    for (int i = 1; i <= lnum; ++i) {
        start = lnum - 1;
        for (c = i, f = huffTree[i].parent; f != 0; c = f, f = huffTree[f].parent) {
            if (huffTree[f].leftchild == c) cd[--start] = '0';
            else cd[--start] = '1';
        }
        huffCode[i].assign(&cd[start]);
    }
    delete[] cd;
}

int HuffMan::Decode(const string codestr, char *txtstr) {
    int k, c;
    char ch;
    c = len;
    k = 0;
    for (int i = 0; i < codestr.length(); i++) {
        ch = codestr[i];
        if (ch == '0') c = huffTree[c].leftchild;       //哈夫曼编码规定，左孩子的前缀从0开始，右边从1开始
        else if (ch == '1') c = huffTree[c].rightchild;
        else if (ch != '1' && ch != '0') return -1; //-1,error
        if (huffTree[c].leftchild == 0 && huffTree[c].rightchild == 0) {
            txtstr[k++] = huffTree[c].data;
            c = len;
        } else ch = '\0';
    }
    if (ch == '\0') return -1;
    else txtstr[k] = '\0';  //结束符，一定要加上
    return 1;   //1,yes
}

int main() {
    int t, n, m;
    int wt[800];
    char dataArray[800];
    HuffMan myHuff;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int j = 0; j < n; j++) cin >> wt[j];
        for (int j = 0; j < n; j++) cin >> dataArray[j];
        myHuff.MakeTree(n, wt, dataArray);
        myHuff.Coding();
        cin >> m;
        while (m--) {
            string str;
            char text[800];
            cin >> str;
            if (myHuff.Decode(str, text) == 1) cout << text << endl;
            else cout << "error" << endl;
        }
        myHuff.Destroy();
    }
}