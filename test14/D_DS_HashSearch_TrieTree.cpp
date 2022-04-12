//
// Created by inver on 2021/12/9.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Trie树的结点，因为是多叉树，所以利用孩子数组表示法
class TrieNode {
public:
    char data;
    bool isWord;    //如果为true，说明这一系列的结点组成了一个单词
    vector<TrieNode *> child;   //这个结点的孩子数组

    TrieNode() {
        child.resize(26, nullptr);
        isWord = false;
    }
};

//Trie树
class TrieTree {
    //Trie的根结点
    TrieNode *root;
public:
    TrieTree() {
        root = new TrieNode();
    }

    //插入，根据单词str
    void insert(string str) {
        TrieNode *p = root;
        //遍历要插入的单词
        for (char i : str) {
            //如果为空，那这个地方可以放一个字符
            if (!(p->child[i - 'a'])) {
                p->child[i - 'a'] = new TrieNode();
                p->child[i - 'a']->data = i;
            }
            //继续遍历这个孩子的结点
            p = p->child[i - 'a'];
        }
        //插入完毕，把最后的结点的isword改为true，即存在一个单词
        p->isWord = true;
    }

    //搜索，并输出前缀单词数
    void search(string str) {
        TrieNode *p = root;
        int cnt = 0;
        //根据前缀遍历
        for (char i : str)
            p = p->child[i - 'a'];
        //如果为空，那么就不存在单词，输出0
        if (p == nullptr) {
            cout << 0 << endl;
            return;
        }
        //否则就递归遍历该节点的孩子结点，找到isword为true的结点，然后cnt++
        searchDiGui(p, cnt);
        cout << cnt << endl;
    }

    void searchDiGui(TrieNode *p, int &cnt) {
        for (auto it : p->child) {
            if (!it) continue;
            if (!it->isWord) {
                searchDiGui(it, cnt);
            } else if (it->isWord) cnt++;
        }
    }

    //层序遍历
    void floorOrder() {
        TrieNode *p = root;
        queue<TrieNode *> myQueue;
        for (int i = 0; i < p->child.size(); i++) {
            if (p->child[i]) myQueue.push(p->child[i]);
        }
        while (!myQueue.empty()) {
            for (int i = 0; i < myQueue.front()->child.size(); i++) {
                if (myQueue.front()->child[i])myQueue.push(myQueue.front()->child[i]);
            }
            cout << myQueue.front()->data;
            myQueue.pop();
        }
        cout << endl;
    }

};

int main() {
    string str;
    while (getline(cin, str)) {
        vector<string> stringArray;
        int p = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                stringArray.push_back(str.substr(p, i - p));
                p = i + 1;
            }
        }
        stringArray.push_back(str.substr(p));
        int t;
        TrieTree tree;
        for (string i : stringArray) {
            tree.insert(i);
        }
        tree.floorOrder();
        cin >> t;
        while (t--) {
            string s;
            cin >> s;
            tree.search(s);
        }
    }
}
