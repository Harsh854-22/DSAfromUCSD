#include <bits/stdc++.h>
using namespace std;

vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> sa(n), rank(n), tmp(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; i++) rank[i] = s[i];
    
    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = a + k < n ? rank[a + k] : -1;
            int rb = b + k < n ? rank[b + k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        }
        rank = tmp;
    }
    return sa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s += "$";
    vector<int> sa = buildSuffixArray(s);
    for (int i = 1; i < sa.size(); i++)
        cout << sa[i] << " \n"[i + 1 == sa.size()];
    return 0;
}
