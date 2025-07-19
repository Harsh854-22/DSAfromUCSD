#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& order) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, adj, visited, order);
    }
    order.push(v);
}

vector<int> toposort(vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    stack<int> order;
    for (int v = 0; v < adj.size(); ++v) {
        if (!visited[v])
            dfs(v, adj, visited, order);
    }

    vector<int> result;
    while (!order.empty()) {
        result.push_back(order.top());
        order.pop();
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);  // directed edge
    }

    vector<int> result = toposort(adj);
    for (int x : result)
        cout << x + 1 << " ";
    cout << endl;
}
