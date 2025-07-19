#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int> &a, int x) {
    int left = 0, right = a.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        cout << binary_search(a, x) << ' ';
    }
}
