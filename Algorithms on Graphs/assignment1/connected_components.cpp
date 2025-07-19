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

int count_components(const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    int count = 0;

    for (int v = 0; v < adj.size(); ++v) {
        if (!visited[v]) {
            dfs(v, adj, visited);
            count++;
        }
    }

    return count;
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

    cout << count_components(adj) << endl;
    return 0;
}
