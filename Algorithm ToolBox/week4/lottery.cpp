#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int x, type, index;
};

bool cmp(const Event &a, const Event &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.type < b.type; // start < point < end
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 0, -1});
        events.push_back({r, 2, -1});
    }
    vector<int> points(m), ans(m);
    for (int i = 0; i < m; ++i) {
        cin >> points[i];
        events.push_back({points[i], 1, i});
    }
    sort(events.begin(), events.end(), cmp);
    int count = 0;
    for (auto &e : events) {
        if (e.type == 0) count++;
        else if (e.type == 2) count--;
        else ans[e.index] = count;
    }
    for (int x : ans) cout << x << ' ';
}
