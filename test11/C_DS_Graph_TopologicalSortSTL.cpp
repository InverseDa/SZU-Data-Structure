//
// Created by inver on 2021/11/18.
//
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    vector<bool> isFinished;      //索引号所指示的顶点是否已处理过
    vector<vector<int> > adjMat;  //邻接矩阵
    int n;                        //顶点数 as 成员变量
public:
    void readAdjMatrix() {
        //从输入读入邻接矩阵，存入this->adjMat
        cin >> this->n;           //顶点数
        for (int i = 0; i < n; ++i) {
            isFinished.push_back(false);
            vector<int> row;
            for (int j = 0; j < n; ++j) {
                int edge;
                cin >> edge;    //读入顶点对i,j之间是否有一条边
                //TODO：将边信息增加入row
                row.push_back(edge);
            }
            //TODO：将row增加入this->adjMat
            adjMat.push_back(row);
        }
    }

    bool isZeroInDegrees(int vertexNo) {
        //判定顶点vertexNo是否没有入度
        //this->adjMat[i][vertexNo] == 0
        //表示顶点i与vertexNo之间没有边相连
        for (int i = 0; i < n; i++) {
            //这样就是表明入度大于0，返回false
            if (adjMat[i][vertexNo] != 0) return false;
        }
        return true;
    }

    int select() {
        //从所有顶点中，选出一个顶点i，满足：
        //1) i没有处理过，即isFinished[i]=false
        //2) i的入度为0
        for (int i = 0; i < n; ++i) {
            //TODO：若顶点i的已经处理过，则pass
            //TODO：若顶点度>0，则pass
            if (isFinished[i] || !isZeroInDegrees(i)) continue;
            //提示：调用isZeroInDegrees
            //TODO: 设置顶点i已经处理过，即isFinished[i]为正确值
            //TODO: 返回i
            isFinished[i] = true;
            return i;
        }
        //TODO: 返回-1, 表示未找到满足1)+2)条件的顶点
        return -1;
    }

    void update(int rootNo) {
        //更新顶点rootNo的出弧，即将顶点rootNo从图中断开
        for (int j = 0; j < n; ++j) {
            //TODO： 设置adjMat[rootNo][j]为0
            adjMat[rootNo][j] = 0;
        }
    }

    /////////////////////////////////////////////////////
    // 拓扑排序主算法
    void topologySort() {
        for (int i = 0; i < n; ++i) {  //遍历n次：即按拓扑序，依次选择（排出）n个顶点
            int root;  // 声明顶点索引号（编号）用于存放本次选出的顶点
            root = select();
            //为-1的话，说明已经输出完毕，应该退出
            if (root == -1) break;
            //更新顶点集合，即把这个顶点和图断连
            update(root);
            cout << root << ' ';
        }
        //TODO：输出一行
        cout << endl;
    }

    void main() {
        readAdjMatrix();
        topologySort();
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph g;
        g.main();
    }
    return 0;
}