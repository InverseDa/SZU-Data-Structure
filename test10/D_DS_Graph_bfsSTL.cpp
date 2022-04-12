//
// Created by inver on 2021/11/14.
//

#include <iostream>
#include <vector>
#include <queue>   //使用队列存放所有待打印（访问）结点

using namespace std;

class Graph {
public:
    vector<vector<int> > adjMat; //领接矩阵，adjMat[i,j]=1 if 顶点索引i,j之间有一条边，
    //adjMat[i,j]=0 if if 顶点索引i,j之间没有一条边
    int n; //顶点个数
    vector<bool> isVisited; //记录每个顶点（索引号值为[0,n)）是否已经按BFS方式访问过
public:
    void printAdjMat() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void readAdjMat() {
        cin >> this->n;               //将结点总数读入成员变量n中
        for (int i = 0; i < n; ++i) {
            isVisited.push_back(false);
            vector<int> row;  //邻接矩阵的一行
            for (int j = 0; j < n; ++j) {
                int edge;
                cin >> edge;
                row.push_back(edge);
            }
            adjMat.push_back(row);
        }
        //printAdjMat();
    }

    void update(queue<int> &my_queue, int rootNo) {
        //更新队列my_queue（存放所有待打印结点），即
        //将rootNo的所有相邻顶点（没有访问过），按索引号从小到大顺序
        //进入my_queue队列
        for (int j = 0; j < n; ++j) {
            if (isVisited[j] || adjMat[rootNo][j] != 1) continue;
            isVisited[j] = true;
            my_queue.push(j);
        }
    }

    void bfs(int startNo = 0) {
        isVisited[startNo] = true;
        //声明队列my_queue: 存放所有待打印的顶点
        //注意：my_queue中的元素（顶点索引）k
        // 满足这个条件：isVisited[k]=true ---- !!!!
        queue<int> my_queue;
        my_queue.push(startNo);
        /////////////////////////////////////////////
        //BFS 主算法
        while (!my_queue.empty()) {
            int root; //声明待打印顶点索引变量
            root = my_queue.front();
            my_queue.pop();
            cout << root << ' ';
            update(my_queue, root);
        }
        cout << endl;
    }

    void main() {
        //BSF入口点
        readAdjMat(); //读邻接矩阵
        bfs();        //做BFS遍历
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph g;
        g.main();       //调用Graph对象的入口点
    }
    return 0;
}