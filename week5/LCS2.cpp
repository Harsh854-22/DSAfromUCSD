#include <iostream>
#include <vector>
using namespace std;

int lcs2(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;

    cout << lcs2(a, b) << endl;
    return 0;
}
