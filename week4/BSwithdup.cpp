#include <iostream>
#include <vector>
using namespace std;

int first_occurrence(const vector<int> &a, int x) {
    int left = 0, right = a.size() - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            result = mid;
            right = mid - 1;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, q, x;
    cin >> n;
    vector<int> a(n);
    for (int &v : a) cin >> v;
    cin >> q;
    while (q--) {
        cin >> x;
        cout << first_occurrence(a, x) << ' ';
    }
}
