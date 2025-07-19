#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int edit_distance(const string& s, const string& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; ++i) dp[i][0] = i;
    for (int j = 0; j <= m; ++j) dp[0][j] = j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int insertion = dp[i][j - 1] + 1;
            int deletion = dp[i - 1][j] + 1;
            int match = dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]);
            dp[i][j] = min(min(insertion, deletion), match);
        }
    }

    return dp[n][m];
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << edit_distance(s, t) << '\n';
    return 0;
}
