#include <iostream>
#include <vector>
#include <map>

using namespace std;

int nodeId = 0;

int newNode() {
    return nodeId++;
}

void buildTrie(const vector<string>& patterns) {
    vector<map<char, int>> trie(1);  // Root is node 0

    for (const string& pattern : patterns) {
        int current = 0;
        for (char ch : pattern) {
            if (trie[current].count(ch)) {
                current = trie[current][ch];
            } else {
                int next = newNode();
                trie[current][ch] = next;
                trie.emplace_back();
                current = next;
            }
        }
    }

    for (int i = 0; i < trie.size(); ++i) {
        // Use C++11 style iteration if C++17 is not available
        for (auto it = trie[i].begin(); it != trie[i].end(); ++it) {
            char ch = it->first;
            int next = it->second;
            cout << i << "->" << next << ":" << ch << "\n";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; ++i) cin >> patterns[i];
    buildTrie(patterns);
}
