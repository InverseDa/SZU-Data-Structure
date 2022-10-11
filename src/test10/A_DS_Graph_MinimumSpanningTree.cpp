//
// Created by inver on 2021/11/11.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int infinity = 65535;

class Edge {
public:
    string begin, end;
    int weight;
};

bool cmp(Edge o1, Edge o2) {
    return o1.weight < o2.weight;
}

class Graph {
public:
    //顶点个数、最小生成树的总权值、Prim算法起点顶点下标、边数
    int vertexNumber, summaryOfW, PrimStarter, edgeNumber;
    //邻接矩阵
    vector<vector<int>> adjMatrix;
    /**Prim**/
    vector<bool> visit;
    /**Prim**/

    /**Kruskal**/
    //边数组，包括起点终点和权值
    vector<Edge> edge;
    //亲戚数组，表示树中结点的连接情况，非0表示相连、0表示不相连（判断是否成环）
    vector<int> parent;
    /**Kruskal**/
    //通过顶点名字获取下标
    unordered_map<string, int> vertexData;
    //通过下标获取顶点
    unordered_map<int, string> vertexFlow;

    Graph(int n);

    void initialGraph();

    void MiniSpanTree_Kruskal();

    int find(int pos);

    void MiniSpanTree_Prim();
};

Graph::Graph(int n) {
    vertexNumber = n;
    summaryOfW = 0;
    //初始化邻接矩阵
    adjMatrix.resize(n, vector<int>(n, infinity));
    visit.resize(n, false);
    for (int i = 0; i < n; i++) {
        adjMatrix[i][i] = 0;
    }
}

void Graph::initialGraph() {
    for (int i = 0; i < vertexNumber; i++) {
        string temp;
        cin >> temp;
        vertexData[temp] = i;
        vertexFlow[i] = temp;
    }
    int m;
    //输入边数，并初始化
    cin >> m;
    edgeNumber = m;
    //输入顶点之间的关系以及权值
    for (int i = 0; i < m; i++) {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        adjMatrix[vertexData[s1]][vertexData[s2]] = w;
        adjMatrix[vertexData[s2]][vertexData[s1]] = w;
        //进入边数组
        if (s1 > s2) edge.push_back({s2, s1, w});
        else edge.push_back({s1, s2, w});
    }
    //Prim算法的起始点设置：
    string starter;
    cin >> starter;
    PrimStarter = vertexData[starter];
}

//Prim算法，设起点顶点为u，总顶点为V
void Graph::MiniSpanTree_Prim() {
    //tempParent是该节点的父亲
    int tempParent = PrimStarter, k = PrimStarter;
    //PrimResult是最终结果
    vector<string> PrimResult;
    //lowcost显示了目前树的边界顶点与其他图的顶点相连的权值
    vector<int> lowcost(vertexNumber, infinity);
    //初始结点已访问
    visit[PrimStarter] = true;
    lowcost = adjMatrix[PrimStarter];
    //-1表示无父亲，后续更新
    parent.resize(vertexNumber, -1);
    //先更新与初始顶点相连的顶点的父亲
    for (int i = 0; i < vertexNumber; i++) {
        if (lowcost[i] < infinity && lowcost[i] > 0) parent[i] = tempParent;
    }
    //遍历V-u的顶点
    for (int i = 1; i < vertexNumber; i++) {
        int min = infinity, t = k;  //k暂存下标
        //在该顶点的相邻顶点找到最小值，而且要求这个相邻顶点未被访问
        for (int i = 0; i < vertexNumber; i++) {
            if (!visit[i] && lowcost[i] <= min) {
                //如果有两个相同的最小权值顶点，那就选择与父亲顶点相连的顶点入树
                if (lowcost[i] == min) {
                    if (parent[i] == parent[t]) {
                        tempParent = parent[i];
                        k = i;
                    }
                } else {
                    min = lowcost[i];
                    tempParent = parent[i];
                    k = i;
                }
            }
        }
        //加入总权值
        summaryOfW += min;
        //设置这个顶点被访问
        visit[k] = true;
        //进入结果
        PrimResult.push_back(vertexFlow[tempParent] + " " + vertexFlow[k] + " " + to_string(min));
        //设置这个顶点的low cost为0，说明之后的结果都不考虑这个定点了（因为它进入树了）
        lowcost[k] = 0;
        //继续修改lowcost的值，目的是更新树的边界顶点的相邻顶点的权值
        for (int i = 0; i < vertexNumber; i++) {
            if (adjMatrix[k][i] < lowcost[i] && i != tempParent) {
                lowcost[i] = adjMatrix[k][i];
                parent[i] = k;
            }
        }
    }
    cout << summaryOfW << endl << "prim:" << endl;
    for (auto it = PrimResult.begin(); it != PrimResult.end(); it++) {
        cout << *it << endl;
    }
}

void Graph::MiniSpanTree_Kruskal() {
    vector<string> KruskalResult;
    parent.resize(edgeNumber, 0);
    //按照权值从小到大排序
    sort(edge.begin(), edge.end(), cmp);
    //初始化parent数组
    for (int i = 0; i < edgeNumber; i++)
        parent[i] = 0;
    //循环，录入结果
    for (int i = 0; i < edgeNumber; i++) {
        //调用find函数，如果n!=m说明未成环，进入KruskalResult数组
        int n = find(vertexData[edge[i].begin]), m = find(vertexData[edge[i].end]);
        if (n != m) {
            parent[n] = m;
            KruskalResult.push_back(edge[i].begin + " " + edge[i].end + " " + to_string(edge[i].weight));
        }
    }
    cout << "kruskal:" << endl;
    for (auto it = KruskalResult.begin(); it != KruskalResult.end(); it++) {
        cout << *it << endl;
    }
}
//并查集
int Graph::find(int pos) {
    while (parent[pos] > 0)
        pos = parent[pos];
    return pos;
}


int main() {
    int n;
    cin >> n;
    Graph myGraph(n);
    myGraph.initialGraph();
    myGraph.MiniSpanTree_Prim();
    myGraph.MiniSpanTree_Kruskal();
}