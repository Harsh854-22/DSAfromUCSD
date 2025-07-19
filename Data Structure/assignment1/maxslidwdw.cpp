#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> max_sliding_window(const vector<int> &a, int w) {
    deque<int> dq;
    vector<int> result;

    for (int i = 0; i < a.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - w)
            dq.pop_front();

        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= w - 1)
            result.push_back(a[dq.front()]);
    }

    return result;
}

int main() {
    int n, w;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cin >> w;

    vector<int> result = max_sliding_window(a, w);
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
