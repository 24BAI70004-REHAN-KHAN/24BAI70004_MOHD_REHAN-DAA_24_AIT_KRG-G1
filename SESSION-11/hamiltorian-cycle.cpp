#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjlist;
vector<int> path;
vector<bool> vis;
int V;

bool hasEdge(int u, int v) {
    for (int x : adjlist[u]) {
        if (x == v) return true;
    }
    return false;
}

bool solve(int u, int cnt) {
    if (cnt == V) {
        return hasEdge(u, path[0]);
    }

    for (int v : adjlist[u]) {
        if (!vis[v]) {
            vis[v] = true;
            path.push_back(v);
            if (solve(v, cnt + 1)) return true;
            vis[v] = false;
            path.pop_back();
        }
    }
    return false;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        V = 5;
        adjlist = {
            {3, 5},
            {0, 2, 3, 4},
            {1, 4},
            {0, 1, 4},
            {1, 2, 3}
        };

        vis.assign(V, false);
        path.clear();

        vis[0] = true;
        path.push_back(0);

        solve(0, 1);
    }
    return 0;
}
