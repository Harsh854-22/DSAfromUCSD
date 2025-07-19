#include <iostream>
#include <set>
#include <map>
using namespace std;

long long MOD = 1000000001;
set<long long> S;
map<long long, long long> prefix;

void insert(long long x) {
    if (S.count(x)) return;
    S.insert(x);
    prefix.clear();
    long long sum = 0;
    for (auto it : S) {
        sum += it;
        prefix[it] = sum;
    }
}

void remove(long long x) {
    if (!S.count(x)) return;
    S.erase(x);
    prefix.clear();
    long long sum = 0;
    for (auto it : S) {
        sum += it;
        prefix[it] = sum;
    }
}

string exists(long long x) {
    return S.count(x) ? "Found" : "Not found";
}

long long range_sum(long long l, long long r) {
    if (S.empty()) return 0;
    auto it_r = S.upper_bound(r);
    if (it_r == S.begin()) return 0;
    --it_r;
    long long sum_r = prefix[*it_r];

    auto it_l = S.lower_bound(l);
    if (it_l == S.begin()) return sum_r;
    --it_l;
    long long sum_l = prefix[*it_l];
    return sum_r - sum_l;
}

int main() {
    int n;
    cin >> n;
    long long last_sum = 0;
    for (int i = 0; i < n; ++i) {
        char cmd;
        cin >> cmd;
        if (cmd == '+' || cmd == '-' || cmd == '?') {
            long long x;
            cin >> x;
            x = (x + last_sum) % MOD;
            if (cmd == '+') insert(x);
            else if (cmd == '-') remove(x);
            else cout << exists(x) << "\n";
        } else if (cmd == 's') {
            long long l, r;
            cin >> l >> r;
            l = (l + last_sum) % MOD;
            r = (r + last_sum) % MOD;
            if (l > r) swap(l, r);
            last_sum = range_sum(l, r);
            cout << last_sum << "\n";
        }
    }
    return 0;
}
