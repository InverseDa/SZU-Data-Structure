//
// Created by inver on 2021/12/22.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 0x3fffffff;

class Edge {
public:
    int begin, end, dis;
};

class Graph {
    vector<vector<int>> adjMat;
    vector<bool> dfsVisit, bfsVisit;
    vector<int> father;
    vector<Edge> edge;
    int vnum, eNum, treeVertexNum;

    void createGraph(int n) {
        adjMat.resize(n, vector<int>(n));
        dfsVisit.resize(n);
        bfsVisit.resize(n);
        father.resize(n, -1);
        vnum = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adjMat[i][j];
                if (adjMat[i][j] == 0) adjMat[i][j] = inf;
            }
        }
    }

    //深度优先搜素
    void dfs(int v) {
        dfsVisit[v] = true;
        for (int i = 0; i < vnum; i++) {
            if (!dfsVisit[i] && adjMat[v][i] != inf)
                dfs(i);
        }
    }

    void dfsTraverse(int v) {
        for (int i = 0; i < vnum; i++) {
            if (!dfsVisit[i]) dfs(i);
        }
    }

    //广度优先搜索
    void bfs(int v) {
        queue<int> myQueue;
        myQueue.push(v);
        bfsVisit[v] = true;
        while (!myQueue.empty()) {
            int data = myQueue.front();
            myQueue.pop();
            for (int i = 0; i < vnum; i++) {
                if (!bfsVisit[i] && adjMat[v][i] < inf) {
                    myQueue.push(i);
                    bfsVisit[i] = true;
                }
            }
        }
    }

    void bfsTraverse(int v) {
        for (int i = 0; i < vnum; i++) {
            if (!bfsVisit[i]) bfs(i);
        }
    }

    int find(int x) {
        int a = x;
        //找到自己的根结点
        while (x != father[x]) {
            x = father[x];
        }
        //路径压缩，优化算法
        while (a != father[a]) {
            int z = a;
            a = father[a];
            father[z] = x;
        }
        return x;
    }

    int Kruskal() {
        int sum = 0;
        for (int i = 0; i < vnum; i++) {
            father[i] = i;
        }
        sort(edge.begin(), edge.end(), [](Edge e1, Edge e2) {
            return e1.dis < e2.dis;
        });
        for (int i = 0; i < edge.size(); i++) {
            int fa = find(edge[i].begin), fb = find(edge[i].end);
            if (fa != fb) {
                father[fa] = fb;
                sum += edge[i].dis;
                treeVertexNum++;
                if (treeVertexNum == vnum - 1) break;
            }
        }
        if (treeVertexNum != vnum - 1) return -1;
        else return sum;
    }

    int Prim(int start) {
        vector<bool> visit(vnum, false);
        vector<int> lowCost = adjMat[start];
        visit[start];
        int sum = 0;
        for (int i = 0; i < vnum; i++) {
            int min = inf, u = -1;
            for (int j = 0; j < vnum; j++) {
                if (!visit[j] && min > lowCost[j]) {
                    u = j;
                    min = lowCost[j];
                }
            }
            if (u == -1) return -1;
            visit[u] = true;
            sum += min;
            for (int v = 0; v < vnum; v++) {
                if (!visit[v] && adjMat[u][v] != inf && adjMat[u][v] < lowCost[v]) {
                    lowCost[v] = adjMat[u][v];
                }
            }
        }
        return sum;
    }

    void dijkstra(int start) {
        vector<int> d = adjMat[start];
        vector<bool> visit(vnum, false);
        d[start] = 0;
        visit[start] = true;
        for (int i = 0; i < vnum; i++) {
            int min = inf, u = -1;
            for (int j = 0; j < vnum; j++) {
                if (!visit[j] && d[j] < min) {
                    u = j;
                    min = d[j];
                }
            }
            if (u == -1) return;
            visit[u] = true;
            for (int v = 0; v < vnum; v++) {
                if (!visit[v] && adjMat[u][v] != inf && d[u] + adjMat[u][v] < d[v]) {
                    d[v] = d[u] + adjMat[u][v];
                }
            }
        }
    }
};

int main() {

}