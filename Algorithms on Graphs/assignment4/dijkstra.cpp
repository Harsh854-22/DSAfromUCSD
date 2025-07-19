#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

long long dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int s, int t) {
    vector<long long> dist(n, INF);
    dist[s] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;

        for (auto [u, w] : adj[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }

    return dist[t] == INF ? -1 : dist[t];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
    }

    int s, t;
    cin >> s >> t;
    cout << dijkstra(n, adj, s - 1, t - 1) << endl;
}
