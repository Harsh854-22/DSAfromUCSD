#include <bits/stdc++.h>
using namespace std;

struct Node {
    int parent, start, *end;
    map<char,int> next;
    Node(int p, int s, int *e) : parent(p), start(s), end(e) {}
};

vector<int> buildSuffixArray(const string &s);
vector<int> buildLCP(const string &s, const vector<int> &sa);

void buildSuffixTree(const string &s, const vector<int> &sa, const vector<int> &lcp) {
    int n = sa.size();
    vector<Node> tree;
    tree.emplace_back(-1, -1, new int(-1));
    int lcpPrev = 0, curNode = 0;

    for (int i = 0; i < n; i++) {
        int suffix = sa[i];
        while (tree[tree[curNode].parent].start >= 0 && 
              (tree[curNode].end ? (*tree[curNode].end) - tree[curNode].start:0) > lcpPrev) {
            curNode = tree[curNode].parent;
        }
        if (tree[curNode].end == nullptr) {
            tree.emplace_back(curNode, suffix + lcpPrev, nullptr);
            tree[curNode].next[s[suffix + lcpPrev]] = tree.size() - 1;
            curNode = tree.size() - 1;
        } else {
            int *splitEnd = new int(tree[curNode].start + lcpPrev);
            tree.emplace_back(tree[curNode].parent, tree[curNode].start, splitEnd);
            tree[tree[curNode].parent].next[s[tree[curNode].start]] = tree.size() - 1;
            tree.emplace_back(tree.size() - 1, suffix + lcpPrev, nullptr);
            tree.back().end = nullptr;
            tree[tree.size()-2].next[s[suffix + lcpPrev]] = tree.size() - 1;
            tree[curNode].start += lcpPrev;
            tree[curNode].parent = tree.size() - 2;
            tree[tree.size()-2].next[s[tree[curNode].start]] = curNode;
            curNode = tree.size() - 1;
        }
        if (i + 1 < n)
            lcpPrev = lcp[i];
    }

    for (int v = 1; v < tree.size(); v++) {
        int p = tree[v].parent;
        if (tree[v].end)
            cout << p << "->" << v << ": " << tree[v].start << " .. " << *tree[v].end << "\n";
        else
            cout << p << "->" << v << ": " << tree[v].start << " .. " << s.size()-1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    s += "$";
    auto sa = buildSuffixArray(s);
    auto lcp = buildLCP(s, sa);
    buildSuffixTree(s, sa, lcp);
    return 0;
}

// Helper: suffix array + Kasai's LCP
vector<int> buildSuffixArray(const string &s) {
    int n = s.size();
    vector<int> sa(n), rank(n), tmp(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; i++) rank[i] = s[i];
    for (int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int a, int b)->bool {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            int ra = a+k<n ? rank[a+k] : -1;
            int rb = b+k<n ? rank[b+k] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);
        rank = tmp;
    }
    return sa;
}

vector<int> buildLCP(const string &s, const vector<int> &sa) {
    int n = s.size(), k = 0;
    vector<int> lcp(n - 1), rank(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) { k = 0; continue; }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
