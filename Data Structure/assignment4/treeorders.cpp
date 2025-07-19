#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key, left, right;
};

vector<int> in_order;
vector<int> pre_order;
vector<int> post_order;

void inOrder(const vector<Node>& tree, int i) {
    if (i == -1) return;
    inOrder(tree, tree[i].left);
    in_order.push_back(tree[i].key);
    inOrder(tree, tree[i].right);
}

void preOrder(const vector<Node>& tree, int i) {
    if (i == -1) return;
    pre_order.push_back(tree[i].key);
    preOrder(tree, tree[i].left);
    preOrder(tree, tree[i].right);
}

void postOrder(const vector<Node>& tree, int i) {
    if (i == -1) return;
    postOrder(tree, tree[i].left);
    postOrder(tree, tree[i].right);
    post_order.push_back(tree[i].key);
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> tree[i].key >> tree[i].left >> tree[i].right;
    }

    inOrder(tree, 0);
    preOrder(tree, 0);
    postOrder(tree, 0);

    for (int x : in_order) cout << x << ' ';
    cout << '\n';
    for (int x : pre_order) cout << x << ' ';
    cout << '\n';
    for (int x : post_order) cout << x << ' ';
    cout << '\n';

    return 0;
}
