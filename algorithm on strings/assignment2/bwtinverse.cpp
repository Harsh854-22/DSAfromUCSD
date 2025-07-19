#include <bits/stdc++.h>
using namespace std;

string inverseBWT(const string &bwt) {
    int n = bwt.size();
    vector<int> count(256, 0);
    for (char ch : bwt) count[(unsigned char)ch]++;
    vector<int> start(256, 0);
    for (int c = 1; c < 256; ++c)
        start[c] = start[c - 1] + count[c - 1];

    vector<int> occ(n);
    vector<int> seen(256, 0);
    for (int i = 0; i < n; ++i) {
        occ[i] = seen[(unsigned char)bwt[i]]++;
    }

    string text;
    text.resize(n);
    int idx = find(bwt.begin(), bwt.end(), '$') - bwt.begin();
    for (int p = n - 1; p >= 0; --p) {
        text[p] = bwt[idx];
        idx = start[(unsigned char)bwt[idx]] + occ[idx];
    }
    return text;
}

int main() {
    string bwt;
    cin >> bwt;
    cout << inverseBWT(bwt) << "\n";
}
