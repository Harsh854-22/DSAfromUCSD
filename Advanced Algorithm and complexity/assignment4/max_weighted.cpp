#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];
int weight[MAXN], dp[MAXN][2];
bool visited[MAXN];

void dfs(int v, int p) {
    visited[v] = true;
    dp[v][0] = 0;
    dp[v][1] = weight[v];
    for (int u : tree[v]) {
        if (u == p) continue;
        dfs(u, v);
        dp[v][0] += max(dp[u][0], dp[u][1]);
        dp[v][1] += dp[u][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> weight[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << "\n";
}
