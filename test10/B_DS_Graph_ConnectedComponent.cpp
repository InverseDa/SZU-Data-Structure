//
// Created by inver on 2021/11/14.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
public:
    //顶点数，边数，连通分量个数
    int vertexNum, edgeNum, sum = 0;
    //顶点表，邻接表，键值对
    vector<string> vertexData;
    vector<vector<int>> adjMatrix;
    unordered_map<string, int> map;
    //访问记录数组
    vector<bool> visited;

    Graph();

    void initialGraph();

    //计算连通分量个数，期间调用dfs（还可以通过bfs和并查集来计算）
    void count();

    void dfs(int v);

    void printGraph();
};

Graph::Graph() {
    int n, m;
    cin >> n;
    vertexNum = n;
    adjMatrix.resize(n, vector<int>(n));
    visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vertexData.push_back(str);
        map[str] = i;
    }
    cin >> m;
    edgeNum = m;
    initialGraph();
}

void Graph::initialGraph() {
    for (int i = 0; i < edgeNum; i++) {
        string prestr, nextstr;
        cin >> prestr >> nextstr;
        adjMatrix[map[prestr]][map[nextstr]] = 1;
        adjMatrix[map[nextstr]][map[prestr]] = 1;
    }
}

void Graph::dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < vertexNum; i++) {
        if (!visited[i] && adjMatrix[v][i] == 1) dfs(i);
    }
}

void Graph::count() {
    for (int i = 0; i < vertexNum; i++) {
        if (!visited[i]) {
            dfs(i);
            //遍历完之后连通分量+1，之后从未访问的顶点继续遍历，如果所有顶点都访问了，那sum就是最终的连通分量个数
            sum++;
        }
    }
}

void Graph::printGraph() {
    for (auto it = vertexData.begin(); it != vertexData.end(); it++) {
        if (it != vertexData.begin()) cout << ' ';
        cout << *it;
    }
    cout << endl;
    for (int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            if (j != 0)cout << ' ';
            cout << adjMatrix[i][j];
        }
        cout << endl;
    }
    count();
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph myGraph;
        myGraph.printGraph();
        cout << endl;
    }
}