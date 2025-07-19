#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> findOccurrences(const string &text, const string &pattern) {
    string s = pattern + "#" + text;
    vector<int> pi = prefixFunction(s);
    vector<int> result;
    int p = pattern.size();
    for (int i = p + 1; i < s.size(); i++) {
        if (pi[i] == p) result.push_back(i - 2 * p);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> pattern >> text;
    vector<int> occ = findOccurrences(text, pattern);

    for (int pos : occ)
        cout << pos << " ";
    cout << "\n";
    return 0;
}
