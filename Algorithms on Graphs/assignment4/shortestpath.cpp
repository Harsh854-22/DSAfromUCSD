#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int from, to, weight;
};

const long long INF = 1e18;

void shortest_paths(int n, int s, const vector<Edge>& edges,
                    vector<long long>& dist,
                    vector<bool>& reachable,
                    vector<bool>& shortest) {
    dist[s] = 0;
    reachable[s] = true;

    // Step 1: Bellman-Ford for n-1 rounds
    for (int i = 0; i < n - 1; ++i) {
        for (const Edge& e : edges) {
            if (dist[e.from] < INF && dist[e.to] > dist[e.from] + e.weight) {
                dist[e.to] = dist[e.from] + e.weight;
                reachable[e.to] = true;
            }
        }
    }

    // Step 2: Detect negative cycles
    queue<int> q;
    vector<bool> inQueue(n, false);
    for (const Edge& e : edges) {
        if (dist[e.from] < INF && dist[e.to] > dist[e.from] + e.weight) {
            q.push(e.to);
            inQueue[e.to] = true;
        }
    }

    // Step 3: Mark all nodes reachable from a negative cycle
    while (!q.empty()) {
        int v = q.front(); q.pop();
        shortest[v] = false;
        for (const Edge& e : edges) {
            if (e.from == v && !inQueue[e.to]) {
                q.push(e.to);
                inQueue[e.to] = true;
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        edges[i].from--;
        edges[i].to--;
    }

    cin >> s;
    s--;

    vector<long long> dist(n, INF);
    vector<bool> reachable(n, false);
    vector<bool> shortest(n, true);

    shortest_paths(n, s, edges, dist, reachable, shortest);

    for (int i = 0; i < n; ++i) {
        if (!reachable[i]) cout << "*\n";
        else if (!shortest[i]) cout << "-\n";
        else cout << dist[i] << "\n";
    }
}
