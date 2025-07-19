#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    double weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int find(int v, vector<int>& parent) {
    if (v != parent[v])
        parent[v] = find(parent[v], parent);
    return parent[v];
}

void unite(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = find(u, parent);
    v = find(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
}

double clustering(vector<pair<double, double>>& points, int k) {
    int n = points.size();
    vector<Edge> edges;

    // Build complete graph
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = hypot(points[i].first - points[j].first,
                             points[i].second - points[j].second);
            edges.push_back({i, j, d});
        }
    }

    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    int components = n;
    for (const Edge& e : edges) {
        if (find(e.u, parent) != find(e.v, parent)) {
            if (components == k)
                return e.weight;  // First edge connecting two clusters
            unite(e.u, e.v, parent, rank);
            components--;
        }
    }

    return 0.0;  // should never happen
}

int main() {
    int n, k;
    cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].first >> points[i].second;
    cin >> k;

    printf("%.10f\n", clustering(points, k));
}
