//
// Created by inver on 2021/11/4.
//

#include <iostream>

using namespace std;

//图
class Graph {
public:
    int vertexNumber;   //顶点数量
    char mode;  //模式：U无向图，D有向图
    string *vertexData; //顶点数据的string数组，比如ABCD，就是{"A"},{"B"},{"C"},{"D"}
    int *degreeVector;  //度的大小数组
    int *inDegree;  //入度大小数组
    int *outDegree; //出度大小数组
    int **adjMatrix;    //邻接矩阵
    string *independentVertex;  //独立顶点string数组
    //初始化图
    void initialGraph(char mode, string vertexdata, int vexnum);

    //初始化邻接矩阵
    void initialAdjacencyMatrix();

    //打印邻接矩阵
    void printMatrix();

    //打印度和独立顶点
    void printDegreeAndIndependentVertex();
};

void Graph::initialGraph(char mode, string vertexdata, int vexnum) {
    this->mode = mode;
    vertexNumber = vexnum;
    /***数组的初始化**/
    adjMatrix = new int *[vertexNumber];
    vertexData = new string[vertexNumber];
    independentVertex = new string[vertexNumber];
    degreeVector = new int[vertexNumber];
    inDegree = new int[vertexNumber];
    outDegree = new int[vertexNumber];
    //创建邻接矩阵
    for (int i = 0; i < vertexNumber; i++) {
        adjMatrix[i] = new int[vertexNumber];
    }
    //设定度和邻接矩阵的值都为0
    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            adjMatrix[i][j] = 0;
        }
        degreeVector[i] = inDegree[i] = outDegree[i] = 0;
    }
    /***数组的初始化**/
    int k = 0;
    for (int i = 0; i < vertexdata.size(); i++) {
        //检测到空格时，k++，加一
        if (vertexdata[i] == ' ') {
            k++;
            continue;
        }
        //当前数组的push函数，把顶点数据推入string中
        vertexData[k].push_back(vertexdata[i]);
    }
}

void Graph::initialAdjacencyMatrix() {
    //前顶点pos1位置，后顶点pos2位置
    string preVertex, nextVertex;
    int n, pos1, pos2;
    cin >> n;
    while (n--) {
        cin >> preVertex >> nextVertex;
        //找位置
        for (int i = 0; i < vertexNumber; i++) {
            if (preVertex == vertexData[i]) pos1 = i;
            if (nextVertex == vertexData[i]) pos2 = i;
        }
        //赋值
        adjMatrix[pos1][pos2] = 1;
        //如果是无向图，还得交换赋值
        if (mode == 'U') adjMatrix[pos2][pos1] = 1;
    }
}

//打印，顺便计算度
void Graph::printMatrix() {
    for (int i = 0; i < vertexNumber; i++) {
        for (int j = 0; j < vertexNumber; j++) {
            if (j != 0) cout << ' ';
            cout << adjMatrix[i][j];
            if (adjMatrix[i][j] == 1) {
                //无向图的度以及有向图的入度
                degreeVector[i]++;
                inDegree[i]++;
            }
        }
        cout << endl;
    }
}

void Graph::printDegreeAndIndependentVertex() {
    int k = 0;
    //无向图
    if (mode == 'U') {
        for (int i = 0; i < vertexNumber; i++) {
            //度为0，说明为独立顶点，并且打印度的情况
            if (!degreeVector[i]) {
                independentVertex[k++].append(vertexData[i]);
                continue;
            }
            cout << vertexData[i] << ": " << degreeVector[i] << endl;
        }
        //最后打印独立顶点
        int t = 0;
        for (int i = 0; i < independentVertex->size(); i++) {
            if (!independentVertex->empty()) {
                cout << independentVertex[i] << endl;
                t++;
            }
        }
        if (t != 0) cout << endl;
    } //有向图
    else {
        //计算出度
        for (int i = 0; i < vertexNumber; i++) {
            for (int j = 0; j < vertexNumber; j++)
                if (adjMatrix[j][i] == 1) outDegree[i]++;
        }
        //度为0，说明为独立顶点，并且打印度的情况
        for (int i = 0; i < vertexNumber; i++) {
            if (!inDegree[i] && !outDegree[i]) {
                independentVertex[k++].append(vertexData[i]);
                continue;
            }
            //度就是入度加出度
            cout << vertexData[i] << ": " << inDegree[i] << ' ' << outDegree[i] << ' ' << inDegree[i] + outDegree[i]
                 << endl;
        }
        //最后打印独立顶点
        int t = 0;
        for (int i = 0; i < independentVertex->size(); i++) {
            if (!independentVertex->empty()) {
                cout << independentVertex[i] << endl;
                t++;
            }
        }
        if (t != 0) cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        char mode;
        int vexnum, n;
        string vertexString;
        Graph myGraph;
        cin >> mode >> vexnum;
        getchar();
        getline(cin, vertexString);
        myGraph.initialGraph(mode, vertexString, vexnum);
        myGraph.initialAdjacencyMatrix();
        myGraph.printMatrix();
        myGraph.printDegreeAndIndependentVertex();
    }
}