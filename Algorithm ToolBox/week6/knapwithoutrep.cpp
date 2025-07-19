#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, const vector<int>& weights) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int w = weights[i - 1];
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (w <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + w);
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W, n;
    cin >> W >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    cout << knapsack(W, weights) << endl;
    return 0;
}
