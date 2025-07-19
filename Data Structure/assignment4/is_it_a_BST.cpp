#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key, left, right;
};

bool isBSTUtil(const vector<Node>& tree, int index, long long minVal, long long maxVal) {
    if (index == -1) return true;
    const Node& node = tree[index];
    if (node.key < minVal || node.key > maxVal) return false;
    bool left = isBSTUtil(tree, node.left, minVal, node.key - 1LL);
    bool right = isBSTUtil(tree, node.right, node.key, maxVal);
    return left && right;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "CORRECT\n";
        return 0;
    }
    vector<Node> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].key >> tree[i].left >> tree[i].right;
    }
    cout << (isBSTUtil(tree, 0, LLONG_MIN, LLONG_MAX) ? "CORRECT" : "INCORRECT") << "\n";
    return 0;
}
