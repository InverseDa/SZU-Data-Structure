//
// Created by inver on 2021/11/4.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//最大顶点数
const int MaxLen = 20;

class Graph {
private:
    vector<bool> visit; //标记顶点是否被访问
    vector<vector<int>> Matrix; //邻接矩阵
    int vertexNumber;   //图的顶点数量
    //深度优先遍历
    void BFS(int v);

public:
    //设置邻接矩阵
    void setMatrix(int vnum, vector<vector<int>> mx);

    //DFS公有函数，深度优先遍历
    void BFSTraverse();
};

void Graph::setMatrix(int vnum, vector<vector<int>> mx) {
    //把主函数来的mx数组传给Matrix，并且设定图的顶点
    vertexNumber = vnum;
    for (int i = 0; i < vertexNumber; i++)
        Matrix.push_back(mx[i]);
    //初始化visit数组
    for (int i = 0; i < vertexNumber; i++)
        visit.push_back(false);
}

void Graph::BFS(int v) {
    int u;
    //辅助队列
    queue<int> myQueue;
    //记录该顶点与其他顶点相连的数组
    int *AdjVex = new int[vertexNumber];
    //初始化AdjVex数组，-1表示不相连
    for (int i = 0; i < vertexNumber; i++) {
        AdjVex[i] = -1;
    }
    //从0开始bfs
    for (int v = 0; v < vertexNumber; v++) {
        //如果未访问
        if (!visit[v]) {
            //设置已访问
            visit[v] = true;
            cout << v << ' ';
            //把这个顶点入队
            myQueue.push(v);
            //当队列不空的时候循环
            while (!myQueue.empty()) {
                //读取队头元素，并出队
                u = myQueue.front();
                myQueue.pop();
                //找到与u相连的顶点，并存到AdjVex数组
                int k = 0;
                for (int i = 0; i < vertexNumber; i++)
                    if (Matrix[u][i] == 1) AdjVex[k++] = i;
                //从u相连的顶点入手，继续遍历
                for (int i = 0; i < k; i++) {
                    //获取与u顶点相连的顶点位置
                    int w = AdjVex[i];
                    //若该节点未被访问，那么就继续遍历
                    if (!visit[w]) {
                        visit[w] = true;
                        cout << w << ' ';
                        //同时入队
                        myQueue.push(w);
                    }
                }
                /*这段代码可以简写成：
                u = myQueue.front();
                myQueue.pop();
                for(int j = 0; j < vertexNumber; j++){
                    if(Matrix[u][j] == 1 && !visit[j]){
                        visit[j] = true;
                        cout<<j<<' ';
                        myQueue.push(j);
                    }
                 }
                 所以根本不需要AdjVex数组！
                 */
            }
        }
    }
    cout << endl;
}

void Graph::BFSTraverse() {
    BFS(0);
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
        myGraph.BFSTraverse();
    }
}