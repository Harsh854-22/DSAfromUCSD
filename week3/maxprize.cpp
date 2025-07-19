#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int k = 1;
    while (n > 2 * k) {
        summands.push_back(k);
        n -= k;
        ++k;
    }
    summands.push_back(n);
    return summands;
}

int main() {
    int n;
    cin >> n;
    vector<int> summands = optimal_summands(n);
    cout << summands.size() << "\n";
    for (int x : summands) cout << x << " ";
    cout << endl;
    return 0;
}
