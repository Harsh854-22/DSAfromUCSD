#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    unordered_map<char, int> next;
    bool isEnd = false;
};

vector<Node> buildTrie(const vector<string> &patterns) {
    vector<Node> trie(1);
    for (const auto &pat : patterns) {
        int v = 0;
        for (char ch : pat) {
            if (!trie[v].next.count(ch)) {
                trie[v].next[ch] = trie.size();
                trie.emplace_back();
            }
            v = trie[v].next[ch];
        }
        trie[v].isEnd = true;
    }
    return trie;
}

// Checks if there's a pattern starting at position i
bool matchFrom(const string &text, int i, const vector<Node> &trie) {
    int v = 0, j = i;
    while (j < (int)text.size()) {
        bool progressed = false;
        
        // Try to match each possible character (exact match or wildcard '?')
        for (auto &kv : trie[v].next) {
            char ch = kv.first;
            int u = kv.second;
            
            if (ch == text[j] || ch == '?') { // Match exact character or wildcard '?'
                v = u;
                progressed = true;
                j++; // Move to the next character in text
                if (trie[v].isEnd) return true; // Pattern found
                break; // Exit the loop once a match is found
            }
        }
        
        if (!progressed) return false; // No match found at this position
    }
    return false;
}

vector<int> trieMatchingExtended(const string &text, const vector<string> &patterns) {
    vector<int> result;
    auto trie = buildTrie(patterns);
    
    for (int i = 0; i < (int)text.size(); i++) {
        if (matchFrom(text, i, trie))
            result.push_back(i); // If a match is found, store the position
    }
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    int n;
    cin >> text >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; i++) cin >> patterns[i];

    auto occ = trieMatchingExtended(text, patterns);
    for (int pos : occ) cout << pos << " "; // Output all found positions
    cout << "\n";
    
    return 0;
}
