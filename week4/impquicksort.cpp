#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

pair<int, int> partition3(vector<int> &a, int l, int r) {
    int x = a[l], lt = l, gt = r;
    for (int i = l + 1; i <= gt;) {
        if (a[i] < x) swap(a[i++], a[lt++]);
        else if (a[i] > x) swap(a[i], a[gt--]);
        else i++;
    }
    return {lt, gt};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
    if (l >= r) return;
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    auto m = partition3(a, l, r);
    randomized_quick_sort(a, l, m.first - 1);
    randomized_quick_sort(a, m.second + 1, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    randomized_quick_sort(a, 0, n - 1);
    for (int x : a) cout << x << ' ';
}
