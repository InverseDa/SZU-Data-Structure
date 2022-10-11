//
// Created by inver on 2021/11/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//原理：建立最小生成树
//边集类
class Edge {
public:
    int first, second, weight;
};
//比较器排序
bool cmp(Edge o1, Edge o2) {
    return o1.weight < o2.weight;
}
//是否包含tempEdge的元素
bool isContainsEdge(Edge o1, vector<Edge> &edge) {
    for (int i = 0; i < edge.size(); i++) {
        if (o1.first == edge[i].first && o1.second == edge[i].second)
            return true;
        if (o1.second == edge[i].first && o1.first == edge[i].second)
            return true;
    }
    return false;
}
//并查集：找父亲
int find(int x, vector<int> &parent) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}
//Kruskal
int kruskal(vector<vector<int>> &adjmatrix, vector<Edge> &edge, vector<int> parent) {
    int sum = 0;
    for (int i = 0; i < edge.size(); i++) {
        //n为边首的父亲，m为边尾的父亲
        int n = find(edge[i].first, parent), m = find(edge[i].second, parent);
        //n！=m说明没有构成环，可加入最小生成树
        if (n != m) {
            parent[n] = m;
            sum += edge[i].weight;
        }
    }
    //最后返回sum
    return sum;
}

int main() {
    int n;
    while (cin >> n) {
        //邻接矩阵
        vector<vector<int>> adjmatrix(n, vector<int>(n));
        vector<Edge> edge, tempEdge;
        vector<int> parent(n, -1);
        int pre, next, t;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> adjmatrix[i][j];
            }
            parent[i] = i;
        }
        cin >> t;
        //tempEdge是已经构造好的边（即已经加入了最小生成树中），Edge是找到还没构造好的边
        while (t--) {
            cin >> pre >> next;
            if (pre > next) swap(pre, next);
            tempEdge.push_back({pre - 1, next - 1, adjmatrix[pre - 1][next - 1]});
            //因为tempEdge是已经构造成最小生成树的边集合，所以要更新他们的父亲
            parent[find(next - 1, parent)] = parent[find(pre - 1, parent)];
        }
        //然后找出没有加入到最小生成树的边集
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (adjmatrix[i][j] != 0 && !isContainsEdge({i, j, adjmatrix[i][j]}, tempEdge)) {
                    edge.push_back({i, j, adjmatrix[i][j]});
                }
            }
        }
        //进行排序，按权值从小到大
        sort(edge.begin(), edge.end(), cmp);
        //Kruskal
        cout << kruskal(adjmatrix, edge, parent) << endl;
    }
}