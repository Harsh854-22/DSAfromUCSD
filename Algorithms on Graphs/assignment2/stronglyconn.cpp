#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs1(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs1(u, adj, visited, finishStack);
    }
    finishStack.push(v);
}

void dfs2(int v, vector<vector<int>>& adjRev, vector<bool>& visited) {
    visited[v] = true;
    for (int u : adjRev[v]) {
        if (!visited[u])
            dfs2(u, adjRev, visited);
    }
}

int numberOfSCCs(vector<vector<int>>& adj, vector<vector<int>>& adjRev) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> finishStack;

    // 1. Order vertices by finish time
    for (int v = 0; v < n; ++v) {
        if (!visited[v])
            dfs1(v, adj, visited, finishStack);
    }

    // 2. Explore reversed graph in that order
    fill(visited.begin(), visited.end(), false);
    int count = 0;
    while (!finishStack.empty()) {
        int v = finishStack.top();
        finishStack.pop();
        if (!visited[v]) {
            dfs2(v, adjRev, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), adjRev(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adjRev[v - 1].push_back(u - 1);
    }

    cout << numberOfSCCs(adj, adjRev) << endl;
}
