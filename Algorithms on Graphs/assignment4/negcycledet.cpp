#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, weight;
};

bool hasNegativeCycle(int n, const vector<Edge>& edges) {
    vector<int> dist(n, 0);  // Initialize to 0 to detect negative cycle anywhere

    for (int i = 0; i < n; ++i) {
        bool updated = false;
        for (const Edge& e : edges) {
            if (dist[e.to] > dist[e.from] + e.weight) {
                dist[e.to] = dist[e.from] + e.weight;
                updated = true;
            }
        }
        if (!updated) break;
        if (i == n - 1 && updated) return true;  // Negative cycle detected
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        edges[i].from--;
        edges[i].to--;
    }

    cout << (hasNegativeCycle(n, edges) ? 1 : 0) << endl;
}
