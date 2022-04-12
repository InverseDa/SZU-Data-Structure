//
// Created by inver on 2021/11/14.
//

#include <iostream>
#include <vector>
#include <unordered_map>
/*
 * adj矩阵：
 * 对角线为1，其他元素均为0
 *
 * */

using namespace std;

const int infinity = 1;

class Graph {
public:
    int vertexNumber, pathNumber = 0;//该顶点经过的路径个数
    float sum = 1.0f;   //单个环的路径之积
    vector<vector<float>> adjMatrix;
    vector<bool> visited;
    vector<string> vertexData;
    //路径数组，记录经过的顶点路径
    vector<int> path;
    unordered_map<string, int> map;

    void dfs(int v);

    void initial();

    void calculatePath();
};

void Graph::initial() {
    int n, m;
    cin >> n >> m;
    vertexNumber = n;
    adjMatrix.resize(n, vector<float>(n, 0));
    visited.resize(n, false);
    path.resize(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        vertexData.push_back(str);
        map[str] = i;
        adjMatrix[i][i] = infinity;
    }
    for (int i = 0; i < m; i++) {
        string pre, next;
        float money;
        cin >> pre >> money >> next;
        adjMatrix[map[pre]][map[next]] = money;
    }
}

void Graph::dfs(int v) {
    visited[v] = true;
    //记录这个顶点的路径（也就是记录顶点的下标）
    path[pathNumber++] = v;
    for (int i = 0; i < vertexNumber; i++) {
        if (!visited[i] && adjMatrix[v][i] != 0)
            dfs(i);
    }
}

void Graph::calculatePath() {
    for (int i = 0; i < vertexNumber; i++) {
        //从第一个顶点开始dfs遍历，第一个顶点的路径就是0 1 2
        pathNumber = 0;
        dfs(i);
        //从这个顶点后一个顶点开始
        for (int j = 1; j < pathNumber; j++) {
            //判断第j个点到起点是否有距离，有的话就进行运算，path表示从起点走到第j个点
            if (adjMatrix[path[j]][i] != 0) {
                int t;
                sum = 1;//因为每个环的路径积不同，所以得重置一次
                for (t = 0; t < j; t++) {
                    //从当前起始顶点乘到终点
                    sum *= adjMatrix[path[t]][path[t + 1]];
                }
                //最后从终点乘到起点，因为这样才是环。单向的话，那么如果起点和终点不重合，那这个环的sum等于0
                sum *= adjMatrix[path[t]][path[0]];
                if (sum > 1) {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
        //每次重置一次遍历过程，路径和访问数组都清空
        visited.resize(vertexNumber, false);
        path.resize(vertexNumber, 0);
    }
    cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph myGraph;
        myGraph.initial();
        myGraph.calculatePath();
    }
}