#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs_shortest_path(const vector<vector<int>>& adj, int s, int t) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (dist[u] == -1) {
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }

    return dist[t];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);  // directed
    }

    int s, t;
    cin >> s >> t;
    cout << bfs_shortest_path(adj, s - 1, t - 1) << endl;
}
