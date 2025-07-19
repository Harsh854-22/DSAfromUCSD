#include <iostream>
#include <vector>
using namespace std;

struct Node {
    long long sum;
    int min, max;
};

class SegmentTree {
    vector<long long> tree;
    int size;

    void build(vector<long long> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size())
                tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2*x+1, lx, m);
        else
            set(i, v, 2*x+2, m, rx);
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
    }

public:
    SegmentTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, 0LL);
    }

    void build(vector<long long> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    int n, m;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SegmentTree st(n);
    st.build(a);

    cin >> m;
    while (m--) {
        string op;
        int x, y;
        cin >> op >> x >> y;
        if (op == "sum") cout << st.sum(x, y+1) << endl;
        else st.set(x, y);
    }
}
