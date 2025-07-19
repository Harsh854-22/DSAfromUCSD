#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> optimal_sequence(int n) {
    vector<int> dp(n + 1, 0);
    vector<int> prev(n + 1, 0);

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        prev[i] = i - 1;
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            prev[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            prev[i] = i / 3;
        }
    }

    vector<int> sequence;
    for (int i = n; i > 0; i = prev[i])
        sequence.push_back(i);
    reverse(sequence.begin(), sequence.end());

    return sequence;
}

int main() {
    int n;
    cin >> n;
    vector<int> sequence = optimal_sequence(n);
    cout << sequence.size() - 1 << "\n";
    for (int x : sequence) {
        cout << x << " ";
    }
    cout << "\n";
}
