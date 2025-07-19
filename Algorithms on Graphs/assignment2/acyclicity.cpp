#include <iostream>
#include <vector>

using namespace std;

bool dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& onStack) {
    visited[v] = true;
    onStack[v] = true;

    for (int u : adj[v]) {
        if (!visited[u] && dfs(u, adj, visited, onStack))
            return true;
        else if (onStack[u])
            return true;
    }

    onStack[v] = false;
    return false;
}

int isAcyclic(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    vector<bool> onStack(adj.size(), false);

    for (int v = 0; v < adj.size(); ++v) {
        if (!visited[v] && dfs(v, adj, visited, onStack))
            return 1;  // cycle found
    }
    return 0;  // no cycle
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    cout << isAcyclic(adj) << endl;
}
