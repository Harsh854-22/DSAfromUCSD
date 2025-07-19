#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Node {
    int key, left, right;
};

bool isBSTHardUtil(const vector<Node>& tree, int index, long long minVal, long long maxVal, bool allowEqualRight) {
    if (index == -1) return true;
    const Node& node = tree[index];

    if ((node.key < minVal) || (node.key > maxVal)) return false;

    bool leftOK = isBSTHardUtil(tree, node.left, minVal, node.key - 1LL, false);
    bool rightOK = isBSTHardUtil(tree, node.right, allowEqualRight ? node.key : node.key + 1LL, maxVal, allowEqualRight);
    return leftOK && rightOK;
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

    cout << (isBSTHardUtil(tree, 0, numeric_limits<long long>::min(), numeric_limits<long long>::max(), true) ? "CORRECT" : "INCORRECT") << "\n";
    return 0;
}
