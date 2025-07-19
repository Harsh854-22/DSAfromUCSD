#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int> &a, vector<int> &b, int left, int mid, int right) {
    long long inv_count = 0;
    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            inv_count += mid - i;
        }
    }
    while (i < mid) b[k++] = a[i++];
    while (j < right) b[k++] = a[j++];
    for (int i = left; i < right; ++i) a[i] = b[i];
    return inv_count;
}

long long count_inversions(vector<int> &a, vector<int> &b, int left, int right) {
    if (right - left <= 1) return 0;
    int mid = (left + right) / 2;
    long long left_inv = count_inversions(a, b, left, mid);
    long long right_inv = count_inversions(a, b, mid, right);
    long long split_inv = merge(a, b, left, mid, right);
    return left_inv + right_inv + split_inv;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    cout << count_inversions(a, b, 0, n) << '\n';
}
