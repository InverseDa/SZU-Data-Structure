//
// Created by inver on 2021/11/4.
//

#include <iostream>

using namespace std;

//邻接表结点
class Node {
public:
    //该顶点的位置
    int vertexPosition;
    Node *next;

    Node();
};

Node::Node() {
    next = nullptr;
}

//邻接表
class AdjList {
public:
    //表头是元素和类似于head指针的firstEdge指针，表示第一边
    char data;
    Node *firstEdge;    //相当于head
    AdjList();
};

AdjList::AdjList() {
    firstEdge = new Node;
}

//图
class Graph {
public:
    //顶点数量
    int vertexNumber;
    //该图的邻接表
    AdjList *adjList;
    //结点元素的string集
    string data;

    //初始化图，初始化顶点数和元素string集
    void initializer(string dataString, int vnum);

    //初始化邻接表
    void initializeList();

    //打印邻接表
    void printList();
};

void Graph::initializer(string dataString, int vnum) {
    vertexNumber = vnum;
    //创建邻接表
    adjList = new AdjList[vertexNumber];
    int k = 0;
    //如果空格，那么跳过
    for (char i : dataString) {
        if (i == ' ') continue;
        data.push_back(i);
        adjList[k++].data = i;
    }
}

void Graph::initializeList() {
    char preVertex, nextVertex;
    //输入有向图的前继顶点和后继顶点
    cin >> preVertex >> nextVertex;
    //获取后继顶点的位置（从data字符串获取）
    int location = data.find(nextVertex);
    for (int i = 0; i < vertexNumber; i++) {
        //如果i所在的数据是前继顶点，那么就进行元素插入
        if (adjList[i].data == preVertex) {
            //p为前继结点，q为后继结点（复习链表）
            Node *p = adjList[i].firstEdge->next, *q = adjList[i].firstEdge;
            //p不为空，就遍历
            while (p != nullptr) {
                p = p->next;
                q = q->next;
            }
            //新建结点，然后赋值
            p = new Node();
            //前继结点的next指针要给p，不然会出错的
            q->next = p;
            p->vertexPosition = location;
            break;
        }
    }
}

//打印邻接表
void Graph::printList() {
    for (int i = 0; i < vertexNumber; i++) {
        //从0开始
        cout << i << " " << adjList[i].data;
        //设置t指针，用来遍历邻接表
        Node *t = adjList[i].firstEdge->next;
        while (t != nullptr) {
            cout << "-" << t->vertexPosition;
            t = t->next;
        }
        //最后加-^表示空
        cout << "-^" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        Graph myGraph;
        cin >> n >> k;
        getchar();
        string dataString;
        getline(cin, dataString);
        myGraph.initializer(dataString, n);
        for (int i = 0; i < k; i++) {
            myGraph.initializeList();
        }
        myGraph.printList();
    }
}