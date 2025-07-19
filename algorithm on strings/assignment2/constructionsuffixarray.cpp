#include <iostream>
#include <vector>
#include <algorithm> // for std::fill
#include <string>    // for std::string

using namespace std;

vector<int> buildSuffixArray(const string &s) {
    int n = s.size(), classes = 256;
    vector<int> sa(n), c(n), cnt(max(n, classes), 0);

    for (char ch : s) cnt[ch]++;
    for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; ++i) sa[--cnt[s[i]]] = i;
    c[sa[0]] = 0; classes = 1;
    for (int i = 1; i < n; ++i) {
        if (s[sa[i]] != s[sa[i - 1]]) classes++;
        c[sa[i]] = classes - 1;
    }

    vector<int> sa2(n), c2(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; ++i) {
            sa2[i] = sa[i] - (1 << h);
            if (sa2[i] < 0) sa2[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int x : sa2) cnt[c[x]]++;
        for (int i = 1; i < classes; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) sa[--cnt[c[sa2[i]]]] = sa2[i];

        c2[sa[0]] = 0; classes = 1;
        for (int i = 1; i < n; ++i) {
            pair<int, int> prev = {c[sa[i - 1]], c[(sa[i - 1] + (1 << h)) % n]};
            pair<int, int> now = {c[sa[i]], c[(sa[i] + (1 << h)) % n]};
            if (now != prev) classes++;
            c2[sa[i]] = classes - 1;
        }
        c.swap(c2);
    }
    return sa;
}

int main() {
    string s;
    cin >> s;
    s += "$";  // sentinel character
    vector<int> sa = buildSuffixArray(s);
    for (int i = 1; i < sa.size(); ++i)
        cout << sa[i] << (i + 1 < sa.size() ? ' ' : '\n');
}
