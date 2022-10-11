//
// Created by inver on 2021/11/4.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
//x偏移量和y偏移量
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
//最终0的个数
int sum = 0;
//n*m决定矩阵
int n, m;

//bfs搜索
void bfs(vector<vector<int>> matrix, int x, int y) {
    //辅助队列
    queue<pair<int, int>> bfsQueue;
    //先设定{0,0}的元素为1
    matrix[x][y] = 1;
    //{0，0}先进入队列
    bfsQueue.push({x, y});
    //开始搜索，只有队列为空的时候跳出循环
    while (!bfsQueue.empty()) {
        //依次遍历队头的坐标，然后出队
        pair<int, int> temp = bfsQueue.front();
        bfsQueue.pop();
        for (int j = 0; j < 4; j++) {
            //四次坐标偏移，偏移后的坐标设为rx和ry
            int rx = temp.first + dx[j], ry = temp.second + dy[j];
            /*前面四个条件保证了矩阵不会越界，因为从0开始，所以上界为n+1(m+1)，下界0(0)，当偏移后的位置元素为0的时候，才可以让这个偏移后坐标入队，
             * 然后设置这个元素为1（所以偏移后元素为1，就无法入队，这样就无法遍历1内部的0了，达到了题意的效。一系列的操作后，这个矩阵就只剩下之前被1围住的0了）*/
            if (rx <= n + 1 && rx >= 0 && ry <= m + 1 && ry >= 0 && matrix[rx][ry] == 0) {
                bfsQueue.push({rx, ry});
                matrix[rx][ry] = 1;
            }
        }
    }
    //bfs搜索完毕，输出sum
    //剩下的0就是被1围起来的0
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (matrix[i][j] == 0) sum++;
    cout << sum << endl;
    /*打印最终的矩阵
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }*/
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<vector<int>> matrix;
        //把原来的矩阵进行了扩充，变成了(n+2)*(m+2)矩阵
        matrix.resize(n + 2, vector<int>(m + 2));
        //从1开始输入矩阵
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
            }
        }
        //实际上，我们通过bfs来把1外部的0都变为1，这样操作下来最终矩阵剩下的0就是被1围城的0，这样就可以用数组遍历简单求出0的个数了！
        bfs(matrix, 0, 0);
        sum = 0;
    }
}