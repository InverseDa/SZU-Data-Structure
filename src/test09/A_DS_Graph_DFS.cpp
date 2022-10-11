//
// Created by inver on 2021/11/3.
//

#include <iostream>
#include <vector>

using namespace std;
//最大顶点数
const int MaxLen = 20;

class Graph {
private:
    vector<bool> visit; //标记顶点是否被访问
    vector<vector<int>> Matrix; //邻接矩阵
    int vertexNumber;   //图的顶点数量
    //深度优先遍历
    void DFS(int v);

public:
    //设置邻接矩阵
    void setMatrix(int vnum, vector<vector<int>> mx);

    //DFS公有函数，深度优先遍历
    void DFSTraverse();
};

void Graph::setMatrix(int vnum, vector<vector<int>> mx) {
    //把主函数来的mx数组传给Matrix，并且设定图的顶点
    vertexNumber = vnum;
    for (int i = 0; i < vertexNumber; i++)
        Matrix.push_back(mx[i]);
}

void Graph::DFSTraverse() {
    //初始化visit数组，把所有顶点都设为未访问状态
    for (int i = 0; i < vertexNumber; i++)
        visit.push_back(false);
    //从0开始DFS搜索
    for (int v = 0; v < vertexNumber; v++)
        //未访问的顶点，就进入DFS函数搜索
        if (!visit[v]) DFS(v);
    cout << endl;
}

void Graph::DFS(int v) {
    //设顶点已经被访问了
    visit[v] = true;
    //打印该结点的位置
    cout << v << ' ';
    int *AdjVex = new int[vertexNumber];
    //初始化AdjVex数组，-1表示不相连
    for (int i = 0; i < vertexNumber; i++) {
        AdjVex[i] = -1;
    }
    int k = 0;
    //找到与v相连的顶点，并存到AdjVex数组
    for (int i = 0; i < vertexNumber; i++) {
        if (Matrix[v][i] == 1) AdjVex[k++] = i;
    }
    for (int i = 0; i < k; i++) {
        if (!visit[AdjVex[i]]) {
            DFS(AdjVex[i]);
        }
    }
    /*这段代码可以改写为
    //设顶点已经被访问了
    visit[v] = true;
    //打印该结点的位置
    cout << v << ' ';
    //继续DFS
    for (int j = 0; j < vertexNumber; j++)
        if (Matrix[v][j] == 1 && !visit[j]) DFS(j);
    */
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int vexNum;
        Graph myGraph;
        cin >> vexNum;
        vector<vector<int>> mx(vexNum, vector<int>(vexNum));
        for (int i = 0; i < vexNum; i++)
            for (int j = 0; j < vexNum; j++)
                cin >> mx[i][j];
        myGraph.setMatrix(vexNum, mx);
        myGraph.DFSTraverse();
    }
}