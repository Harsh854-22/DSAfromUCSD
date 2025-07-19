#include <bits/stdc++.h>
using namespace std;

vector<int> buildSuffixArray(const string &s);
// As defined above...

vector<int> suffixArrayMatching(const string &s, const vector<int> &sa, const string &pat) {
    int n = s.size(), p = pat.size();
    int left = -1, right = n;
    auto cmp = [&](int i, const string& t) -> bool {
        return s.compare(i, t.size(), t) < 0;
    };
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (cmp(sa[mid], pat)) left = mid; else right = mid;
    }
    int l = right;

    left = -1; right = n;
    auto cmp2 = [&](const string &t, int i) -> bool {
        return t.compare(0, t.size(), s, i, t.size()) < 0;
    };
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (cmp2(pat, sa[mid])) right = mid; else left = mid;
    }
    int r = left;

    vector<int> result;
    for (int i = l; i <= r; i++)
        result.push_back(sa[i]);

    sort(result.begin(), result.end());
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s += "$";
    auto sa = buildSuffixArray(s);

    int q; cin >> q;
    while (q--) {
        string pat; cin >> pat;
        auto occ = suffixArrayMatching(s, sa, pat);
        for (int pos : occ)
            cout << pos << " ";
        if (occ.empty()) cout << "\n";
        else cout << "\n";
    }
    return 0;
}
