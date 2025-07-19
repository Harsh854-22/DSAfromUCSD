#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
    map<char, int> children;
    bool isEndOfPattern = false;  // Flag to mark the end of a pattern
};

vector<Node> buildTrie(const vector<string>& patterns) {
    vector<Node> trie(1);  // Root node
    for (const string& pattern : patterns) {
        int current = 0;
        for (char ch : pattern) {
            if (!trie[current].children.count(ch)) {
                trie.push_back(Node());
                trie[current].children[ch] = trie.size() - 1;
            }
            current = trie[current].children[ch];
        }
        // Mark the end of the pattern
        trie[current].isEndOfPattern = true;
    }
    return trie;
}

vector<int> trieMatching(const string& text, const vector<string>& patterns) {
    vector<int> result;
    auto trie = buildTrie(patterns);

    for (int i = 0; i < text.size(); ++i) {
        int current = 0;
        int pos = i;
        while (pos < text.size() && trie[current].children.count(text[pos])) {
            current = trie[current].children[text[pos]];
            if (trie[current].isEndOfPattern) {  // Pattern ends here
                result.push_back(i);
                break;
            }
            pos++;
        }
    }

    return result;
}

int main() {
    string text;
    int n;
    cin >> text >> n;
    vector<string> patterns(n);
    for (int i = 0; i < n; ++i) cin >> patterns[i];

    vector<int> result = trieMatching(text, patterns);
    for (int i : result) cout << i << " ";
    cout << endl;
}
