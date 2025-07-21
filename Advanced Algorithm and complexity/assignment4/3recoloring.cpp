#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;

bool dfs(int v, int c) {
    color[v] = c;
    for (int u : adj[v]) {
        if (color[u] == c) return false;
        if (color[u] == -1 && !dfs(u, (c + 1) % 3)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    color.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
        if (color[i] == -1 && !dfs(i, 0)) {
            cout << "NO\n";
            return 0;
        }

    cout << "YES\n";
    for (int c : color)
        cout << c + 1 << " ";
    cout << "\n";
}
