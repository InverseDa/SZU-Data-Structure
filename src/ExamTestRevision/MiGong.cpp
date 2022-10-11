//
// Created by inver on 2021/12/22.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {-1, 0, 1, 0};

int main() {
    int n;
    cin >> n;
    /*
    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<bool>> hash(n, vector<bool>(n));*/
    int **matrix = new int *[n];
    bool **hash = new bool *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        hash[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            hash[i][j] = false;
        }
    }
    stack<pair<int, int>> path;
    int i = 0, j = 0;
    path.push({0, 0});
    do {
        //遇到边界直接跳出循环
        if (i == n - 1 && j == n - 1) break;
        //依次判断旁边有没有路
        if (i < n - 1 && matrix[i + 1][j] != 1 && !hash[i + 1][j]) {
            path.push({i + 1, j});
            hash[i + 1][j] = true;
            i++;
        } else if (j < n - 1 && matrix[i][j + 1] != 1 && !hash[i][j + 1]) {
            path.push({i, j + 1});
            hash[i][j + 1] = true;
            j++;
        } else if (i >= 0 && matrix[i - 1][j] != 1 && !hash[i - 1][j]) {
            path.push({i - 1, j});
            hash[i - 1][j] = true;
            i--;
        } else if (j >= 0 && matrix[i][j - 1] != 1 && !hash[i][j - 1]) {
            path.push({i, j - 1});
            hash[i][j - 1] = true;
            j--;
        }
            //都没有路，那么就返回
        else {
            i = path.top().first;
            j = path.top().second;
            if (!(i < n - 1 && matrix[i + 1][j] != 1 && !hash[i + 1][j]) &&
                !(j < n - 1 && matrix[i][j + 1] != 1 && !hash[i][j + 1])
                && !(i >= 0 && matrix[i - 1][j] != 1 && !hash[i - 1][j]) &&
                !(j >= 0 && matrix[i][j - 1] != 1 && !hash[i][j - 1]))
                path.pop();
        }
    } while (!path.empty());    //继续循环的条件：当栈不为空的时候，就可以进行循环，寻找路径
    pair<int, int> *finalPath = new pair<int, int>[path.size()];
    int size = path.size();
    for (int i = 0; i < size; i++) {
        finalPath[i] = path.top();
        path.pop();
    }
    for (int i = 0; i < size; i++) {
        cout << finalPath[i].first << ", " << finalPath[i].second << "--->";
    }
    cout << endl;
}
