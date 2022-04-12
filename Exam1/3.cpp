//
// Created by inver on 2021/12/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Node {
public:
    Node *lc, *rc;
    int data;
};

class Tree {
public:
    vector<int> postOrder, inOrder;
    vector<pair<int, int>> leaves;
    Node *root;

    void create(int root, int begin, int end, Node *&t) {
        if (begin > end) {
            t = nullptr;
            return;
        }
        int i = begin;
        while (i < end && inOrder[i] != postOrder[root]) i++;
        t = new Node;
        t->data = postOrder[root];
        create(root - 1 - end + i, begin, i - 1, t->lc);
        create(root - 1, i + 1, end, t->rc);
    }

    void calculate(Node *t, int bian) {
        if (!t) return;
        if (!t->rc && !t->lc) {
            leaves.emplace_back(t->data, t->data * bian);
        }
        calculate(t->lc, bian + 1);
        calculate(t->rc, bian + 1);
    }
};

int main() {
    int n;
    while (cin >> n) {
        vector<int> in, post;

        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            in.push_back(val);
        }
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            post.push_back(val);
        }
        Tree tree;
        tree.postOrder = post;
        tree.inOrder = in;
        tree.create(n - 1, 0, n - 1, tree.root);
        tree.calculate(tree.root, 0);
        sort(tree.leaves.begin(), tree.leaves.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        cout << tree.leaves[0].first << endl;
    }
}
