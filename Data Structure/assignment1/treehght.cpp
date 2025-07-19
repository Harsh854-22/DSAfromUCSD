#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int height(int node, const vector<vector<int>> &tree) {
    int h = 1;
    for (int child : tree[node])
        h = max(h, 1 + height(child, tree));
    return h;
}

int main() {
    int n;
    cin >> n;
    vector<int> parent(n);
    vector<vector<int>> tree(n);
    int root = -1;

    for (int i = 0; i < n; i++) {
        cin >> parent[i];
        if (parent[i] == -1)
            root = i;
        else
            tree[parent[i]].push_back(i);
    }

    cout << height(root, tree) << endl;
    return 0;
}
