//
// Created by inver on 2021/11/18.
//


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

const int infinity = INT16_MAX;

using namespace std;

class Graph {
    //顶点数，起点
    int vertexNumber{}, starter{};
    //邻接矩阵
    vector<vector<int>> adjMatrix;
    //记录是否被访问
    vector<bool> visited;
    //D为最短路径数值的存储数组，从starter到v1,v2,v...；P为路径记录数组
    vector<int> D, P;
public:
    void initial();

    void dijkstra();

    void printPath();
};

void Graph::initial() {
    cin >> vertexNumber;
    adjMatrix.resize(vertexNumber, vector<int>(vertexNumber));
    visited.resize(vertexNumber, false);
    D.resize(vertexNumber);
    P.resize(vertexNumber, -1);
    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j] == 0) adjMatrix[i][j] = infinity;
        }
        adjMatrix[i][i] = 0;
    }
    cin >> starter;
}

void Graph::dijkstra() {
    //有点像prim，D类似于lowcost
    D = adjMatrix[starter];
    visited[starter] = true;
    //从起点以外的点遍历，先寻找最小值
    for (int i = 1; i < vertexNumber; i++) {
        int min = infinity, pos = -1;
        for (int j = 0; j < vertexNumber; j++) {
            //如果有最小值
            if (!visited[j] && D[j] < infinity && min > D[j]) {
                min = D[j];
                pos = j;
            }
        }
        //标记该节点被访问
        visited[pos] = true;
        //更新
        for (int j = 0; j < vertexNumber; j++) {
            //如果经过v的顶点路径比现在的路径短，那就更新D数组和P数组
            if (!visited[j] && (min + adjMatrix[pos][j] < D[j])) {
                D[j] = min + adjMatrix[pos][j];
                P[j] = pos;
            }
        }
    }
}

void Graph::printPath() {
    for (int i = 0; i < vertexNumber; i++) {
        if (i == starter) continue;
        //表示starter和i的路径
        cout << starter << "-" << i << "-" << D[i] << "----";
        int j = i;
        //用stack保存最短路径经过的顶点
        stack<int> pathVertex;
        pathVertex.push(j);
        while (true) {
            j = P[j];
            if (j == -1) {
                pathVertex.push(starter);
                break;
            }
            pathVertex.push(j);
        }
        //倒序输出
        int size = pathVertex.size();
        cout << '[';
        for (int k = 0; k < size; k++) {
            cout << pathVertex.top() << ' ';
            pathVertex.pop();
        }
        cout << "]\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph myGraph;
        myGraph.initial();
        myGraph.dijkstra();
        myGraph.printPath();
    }
}