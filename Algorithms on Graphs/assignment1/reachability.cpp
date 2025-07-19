#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

int reachability(const vector<vector<int>>& adj, int x, int y) {
    vector<bool> visited(adj.size(), false);
    dfs(x, adj, visited);
    return visited[y] ? 1 : 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    int x, y;
    cin >> x >> y;
    cout << reachability(adj, x - 1, y - 1) << endl;
    return 0;
}
