#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> buildFirstOcc(const string &bwt) {
    string sortedBWT = bwt;
    sort(sortedBWT.begin(), sortedBWT.end());
    unordered_map<char, int> firstOcc;
    for (int i = 0; i < sortedBWT.size(); ++i)
        if (!firstOcc.count(sortedBWT[i]))
            firstOcc[sortedBWT[i]] = i;
    return firstOcc;
}

unordered_map<char, vector<int>> buildCount(const string &bwt) {
    unordered_map<char, vector<int>> occCounts;
    for (char ch : bwt)
        occCounts[ch].push_back(0);
    for (auto &kv : occCounts)
        kv.second[0] = 0;
    for (int i = 0; i < bwt.size(); ++i) {
        for (auto &kv : occCounts)
            kv.second[i] = (i > 0 ? kv.second[i - 1] : 0);
        occCounts[bwt[i]][i]++;
    }
    return occCounts;
}

int betterBWMatching(const string &bwt, const string &pattern,
                     const unordered_map<char,int> &firstOcc,
                     const unordered_map<char, vector<int>> &occCounts) {
    int top = 0, bottom = bwt.size() - 1;
    int p = pattern.size() - 1;
    while (top <= bottom) {
        if (p >= 0) {
            char symbol = pattern[p--];
            if (!occCounts.count(symbol)) return 0;

            int topCnt = (top > 0 ? occCounts.at(symbol)[top - 1] : 0);
            int bottomCnt = occCounts.at(symbol)[bottom];
            if (bottomCnt - topCnt > 0) {
                top = firstOcc.at(symbol) + topCnt;
                bottom = firstOcc.at(symbol) + bottomCnt - 1;
            } else {
                return 0;
            }
        } else {
            return bottom - top + 1;
        }
    }
    return 0;
}

int main() {
    string bwt;
    int n;
    cin >> bwt >> n;
    auto firstOcc = buildFirstOcc(bwt);
    auto occCounts = buildCount(bwt);
    while (n--) {
        string pattern;
        cin >> pattern;
        cout << betterBWMatching(bwt, pattern, firstOcc, occCounts)
             << (n > 0 ? ' ' : '\n');
    }
}
