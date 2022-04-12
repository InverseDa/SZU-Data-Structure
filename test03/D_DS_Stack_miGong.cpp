
//
// DS-堆栈-迷宫
//

#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));  //迷宫图
        //vector<vector<int>> hash(n, vector<int>(n));    //用哈希表存储走过的路径，走过记为1
        stack<pair<int, int>> path;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        int i = 0, j = 0;
        path.push({i, j});
        //hash[i][j] = 1;
        matrix[0][0] = 1;
        do {
            if (i == n - 1 && j == n - 1) break;
            //前条件保证了i，j不越界的情况
            if (n > j + 1 && !matrix[i][j + 1]) { //右边有路且没走过
                matrix[i][j + 1] = 1;
                path.push({i, ++j});
            } else if (n > i + 1 && !matrix[i + 1][j]) {   //下边有路且没走过
                matrix[i + 1][j] = 1;
                path.push({++i, j});
            } else if (j - 1 >= 0 && !matrix[i][j - 1]) {   //左边有路且没走过
                matrix[i][j - 1] = 1;
                path.push({i, --j});
            } else if (i - 1 >= 0 && !matrix[i - 1][j]) {   //上边有路且没走过
                matrix[i - 1][j] = 1;
                path.push({--i, j});
            } else {    //无路可走，或者有路了但都走过，只能往回走
                i = path.top().first;
                j = path.top().second;
                bool youbian = n > j + 1 && !matrix[i][j + 1], xiabian =
                        n > i + 1 && !matrix[i + 1][j], zuobian =
                        j - 1 >= 0 && !matrix[i][j - 1], shangbian =
                        i - 1 >= 0 && !matrix[i - 1][j];
                if (!(youbian || xiabian || zuobian || shangbian)) path.pop();
            }
        } while (!path.empty());

        vector<pair<int, int>> finalpath;
        int size = path.size();
        if (size == 0) cout << "no path" << endl;
        else {
            int cnt = 0;    //换行标识符
            for (int i = 0; i < size; i++) {
                finalpath.push_back(path.top());
                path.pop();
            }
            for (auto it = finalpath.rbegin(); it != finalpath.rend(); it++) {
                cout << "[" << it->first << "," << it->second << "]--";
                if (++cnt % 4 == 0) cout << endl;
            }
            cout << "END" << endl;
        }

    }
}
