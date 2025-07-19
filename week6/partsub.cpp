#include <iostream>
#include <vector>
using namespace std;

bool partition3(vector<int>& A) {
    int sum = 0;
    for (int a : A)
        sum += a;
    if (sum % 3 != 0)
        return false;
    
    int target = sum / 3, n = A.size();
    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(target + 1, vector<bool>(target + 1, false)));
    dp[0][0][0] = true;

    for (int i = 1; i <= n; ++i) {
        int a = A[i - 1];
        for (int j = 0; j <= target; ++j) {
            for (int k = 0; k <= target; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (j >= a)
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - a][k];
                if (k >= a)
                    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k - a];
            }
        }
    }

    return dp[n][target][target];
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cout << partition3(A) << endl;
    return 0;
}
