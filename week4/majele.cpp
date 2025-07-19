#include <iostream>
#include <vector>
using namespace std;

int majority_element(vector<int> &a, int left, int right) {
    if (left == right) return -1;
    if (left + 1 == right) return a[left];

    int mid = left + (right - left) / 2;
    int l = majority_element(a, left, mid);
    int r = majority_element(a, mid, right);

    int l_count = 0, r_count = 0;
    for (int i = left; i < right; ++i) {
        if (a[i] == l) ++l_count;
        if (a[i] == r) ++r_count;
    }

    int len = right - left;
    if (l_count > len / 2) return l;
    if (r_count > len / 2) return r;
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    cout << (majority_element(a, 0, a.size()) != -1) << '\n';
}
