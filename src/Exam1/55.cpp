//
// Created by zty on 2021/12/24.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    Node *lc, *rc;
    int data;
};

class Tree {
public:
    Node *root = new Node;

    void createTree(vector<int> &arr, Node *&t, int k) {
        if (k >= arr.size()) {
            t = nullptr;
            return;
        }
        t = new Node;
        t->data = arr[k];
        createTree(arr, t->lc, 2 * k + 1);
        createTree(arr, t->rc, 2 * k + 2);
    }

    void PostOrder(Node *t) {
        if (!t) return;
        PostOrder(t->lc);
        PostOrder(t->rc);
        cout << t->data << " ";
    }
};

//创建小顶堆
void HeapAdjust(vector<int> &arr, int father, int len) {
    int temp = arr[father];
    int child = 2 * father + 1;

    while (child < len) {
        if (child + 1 < len && arr[child + 1] < arr[child]) child++;

        if (temp <= arr[child]) break;

        arr[father] = arr[child];

        father = child;
        child = 2 * child + 1;
    }
    arr[father] = temp;
}

//输出堆的后序遍历，实质是堆排序；但本处采用的是构造树的方法来输出后序遍历
void Heap(vector<int> &arr, Tree &tree) {
    for (int i = arr.size() / 2; i >= 0; i--) {
        HeapAdjust(arr, i, (int) arr.size());
    }
    tree.createTree(arr, tree.root, 0);
    tree.PostOrder(tree.root);
    cout << endl;
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Tree tree;
    Heap(arr, tree);
}
