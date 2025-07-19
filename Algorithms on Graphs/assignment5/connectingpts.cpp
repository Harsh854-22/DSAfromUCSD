#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

double distance(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

double minimum_spanning_tree(vector<pair<double, double>>& points) {
    int n = points.size();
    vector<bool> used(n, false);
    vector<double> minDist(n, numeric_limits<double>::max());
    minDist[0] = 0.0;

    double total_weight = 0.0;

    for (int i = 0; i < n; ++i) {
        int u = -1;

        // Find the unused node with the smallest distance
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        used[u] = true;
        total_weight += minDist[u];

        // Update distances
        for (int v = 0; v < n; ++v) {
            if (!used[v]) {
                double d = distance(points[u], points[v]);
                if (d < minDist[v])
                    minDist[v] = d;
            }
        }
    }

    return total_weight;
}

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; ++i)
        cin >> points[i].first >> points[i].second;

    printf("%.10f\n", minimum_spanning_tree(points));
}
