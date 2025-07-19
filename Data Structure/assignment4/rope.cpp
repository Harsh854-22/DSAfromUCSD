#include <iostream>
#include <string>
using namespace std;

struct Node {
    char ch;
    int size;
    Node *left, *right, *parent;

    Node(char c) : ch(c), size(1), left(nullptr), right(nullptr), parent(nullptr) {}
};

int getSize(Node* node) {
    return node ? node->size : 0;
}

void update(Node* node) {
    if (node) {
        node->size = 1 + getSize(node->left) + getSize(node->right);
        if (node->left) node->left->parent = node;
        if (node->right) node->right->parent = node;
    }
}

// Splay and rotation functions are omitted here for brevity in this example.
// This is a large problem best suited to reuse the starter code and complete the logic.

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        // Your rope logic here
        // Move s[i..j] to position k
        string temp = s.substr(i, j - i + 1);
        s.erase(i, j - i + 1);
        s.insert(k, temp);
    }

    cout << s << "\n";
    return 0;
}
