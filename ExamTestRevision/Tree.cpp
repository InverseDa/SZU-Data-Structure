//
// Created by inver on 2021/12/22.
//
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    vector<Node *> child;
    char data;
};

class Tree {
    Node *root;
    int treeNum;
    //并查集
    vector<int> father;

    Tree() {
        father.resize(treeNum, -1);
    }

    void createTree() {

    }

    int find(int x) {
        while (x != father[x]) {
            x = father[x];
        }
        return x;
    }
};

int main() {}
