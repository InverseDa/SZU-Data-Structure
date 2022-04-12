//
// Created by zty on 2021/12/24.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 0x3fffffff;

class Graph {
public:
    vector<vector<int>> adjmat;
    vector<int> d;
    int vnum;

    void create(int n) {
        vnum = n;
        adjmat.resize(vnum, vector<int>(vnum));
        for (int i = 0; i < vnum; i++) {
            for (int j = 0; j < vnum; j++) {
                cin >> adjmat[i][j];
                if (adjmat[i][j] == 0) adjmat[i][j] = inf;
            }
        }
    }

    void dijkstra(int start) {
        d = adjmat[start];
        vector<bool> visit(vnum, false);
        d[start] = 0;
        visit[start] = true;
        for (int i = 0; i < vnum; i++) {
            int min = inf, u;
            for (int j = 0; j < vnum; j++) {
                if (!visit[j] && d[j] < inf && d[j] < min) {
                    u = j;
                    min = d[j];
                }
            }
            visit[u] = true;
            for (int v = 0; v < vnum; v++) {
                if (!visit[v] && adjmat[u][v] != inf && d[u] + adjmat[u][v] < d[v]) {
                    d[v] = adjmat[u][v] + d[u];
                }
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, start, cnt, k = 1, min = inf, p = 0;
        cin >> n;
        Graph g;
        g.create(n);
        cin >> start >> cnt;
        g.dijkstra(start);
        vector<pair<int, int>> final;
        vector<int> vertex;
        for (int i = 0; i < g.d.size(); i++) {
            final.emplace_back(i, g.d[i]);
        }
        sort(final.begin(), final.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        for (auto &i : final) {
            if (i.second == 0) continue;
            if (k == cnt) {
                min = i.second;
                vertex.push_back(i.first);
                k++;
                continue;
            }
            if (min == i.second) vertex.push_back(i.first);
            k++;
        }
        sort(vertex.begin(), vertex.end());
        for (int i = 0; i < vertex.size(); i++) {
            if (i != 0) cout << " ";
            cout << vertex[i];
        }
        cout << endl;
    }
}
