#include <bits/stdc++.h>
using namespace std;

vector<int> buildSuffixArray(const string &s);  // same as above

int main() {
    string s;
    cin >> s;
    s += "$";
    auto sa = buildSuffixArray(s);
    string bwt;
    int n = s.size();
    bwt.reserve(n);
    for (int i = 0; i < n; ++i) {
        int j = (sa[i] + n - 1) % n;
        bwt.push_back(s[j]);
    }
    cout << bwt << "\n";
}
