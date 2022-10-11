//
// Created by inver on 2021/11/14.
//

#include <iostream>

using namespace std;

class Graph {
public:
    //顶点数,连通分量个数
    int vertexNum, sum = 0;
    //顶点表，邻接表
    int **adjmatrix;
    //访问记录数组
    bool *visited;

    void initial();

    bool isStrengthConnectedComponment();

    void dfs(int v);
};

void Graph::dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < vertexNum; i++) {
        if (!visited[i] && adjmatrix[v][i] == 1) dfs(i);
    }
}

//判断是否为强连通图
bool Graph::isStrengthConnectedComponment() {
    //先开始dfs
    dfs(0);
    //如果有顶点未访问，说明这个图不是强连通
    for (int i = 0; i < vertexNum; i++)
        if (!visited[i]) return false;
    //邻接矩阵倒置
    for (int i = 0; i < vertexNum; i++) {
        visited[i] = false;
        for (int j = 0; j < vertexNum; j++)
            adjmatrix[i][j] = adjmatrix[j][i];
    }
    //倒置再访问
    dfs(0);
    for (int i = 0; i < vertexNum; i++)
        if (!visited[i]) return false;
    return true;
}

void Graph::initial() {
    int n;
    cin >> n;
    vertexNum = n;
    adjmatrix = new int *[n];
    visited = new bool[n];
    for (int i = 0; i < vertexNum; i++)
        adjmatrix[i] = new int[n];
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            cin >> adjmatrix[i][j];
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph myGraph;
        myGraph.initial();
        if (myGraph.isStrengthConnectedComponment()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

