#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs3(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
    int n = a.size(), m = b.size(), o = c.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(o + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= o; ++k) {
                if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
            }
        }
    }

    return dp[n][m][o];
}

int main() {
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;

    cin >> l;
    vector<int> c(l);
    for (int& x : c) cin >> x;

    cout << lcs3(a, b, c) << '\n';
    return 0;
}
