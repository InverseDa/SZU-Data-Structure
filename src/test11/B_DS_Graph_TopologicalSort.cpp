//
// Created by inver on 2021/11/18.
//

#include <iostream>

using namespace std;

class Graph {
    int vertexNum;
    //邻接矩阵
    int **adjMatrix;
    //访问数组
    bool *visited;
public:
    void initial();
    //判断入度是否等于0，接受一个顶点下标
    bool isZeroDegree(int vertex);
    //拓扑排序
    void TopologicalSort();
    //选择一个未被访问，且入读为0的顶点
    int select();
    //更新顶点，即把已经输出过的顶点与图断连
    void update(int rootNo);
};

void Graph::initial() {
    cin >> vertexNum;
    adjMatrix = new int *[vertexNum];
    visited = new bool[vertexNum];
    for (int i = 0; i < vertexNum; i++) {
        adjMatrix[i] = new int[vertexNum];
        visited[i] = false;
    }
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            cin >> adjMatrix[i][j];
        }
    }
}

void Graph::TopologicalSort() {
    for (int i = 0; i < vertexNum; i++) {
        //选择一个顶点
        int root = select();
        //为-1的话，说明已经输出完毕，应该退出
        if (root == -1) break;
        //更新顶点集合，即把这个顶点和图断连
        update(root);
        cout << root << ' ';
    }
    cout << endl;
}

bool Graph::isZeroDegree(int vertex) {
    for (int i = 0; i < vertexNum; i++) {
        //这样就是表明入度大于0，返回false
        if (adjMatrix[i][vertex] != 0) return false;
    }
    return true;
}

int Graph::select() {
    //从所有顶点中，选出一个顶点i，满足未被访问且入度等于0
    for (int i = 0; i < vertexNum; i++) {
        if (visited[i] || !isZeroDegree(i)) continue;
        visited[i] = true;
        //返回顶点
        return i;
    }
    return -1;
}

void Graph::update(int rootNo) {
    //更新顶点rootNo的出弧，即将顶点rootNo从图中断开
    for (int j = 0; j < vertexNum; ++j) {
        adjMatrix[rootNo][j] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph graph;
        graph.initial();
        graph.TopologicalSort();
    }
}