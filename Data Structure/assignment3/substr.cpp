#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll X = 263;

vector<ll> precompute_hashes(const string& s, ll p, ll x) {
    int n = s.size();
    vector<ll> H(n + 1);
    H[0] = 0;
    for (int i = 1; i <= n; i++) {
        H[i] = (x * H[i - 1] + s[i - 1]) % p;
    }
    return H;
}

ll poly_hash(const string& s, ll p, ll x) {
    ll hash = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        hash = (hash * x + s[i]) % p;
    }
    return hash;
}

ll get_substring_hash(const vector<ll>& H, int start, int length, ll p, ll x, const vector<ll>& xpows) {
    ll y = xpows[length];
    ll hash = (H[start + length] - y * H[start]) % p;
    if (hash < 0) hash += p;
    return hash;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    int len = s.length();
    vector<ll> xpows(len + 1);
    xpows[0] = 1;
    for (int i = 1; i <= len; i++)
        xpows[i] = (xpows[i - 1] * X) % MOD;

    vector<ll> H = precompute_hashes(s, MOD, X);

    while (n--) {
        int a, b, l;
        cin >> a >> b >> l;
        ll hash1 = get_substring_hash(H, a, l, MOD, X, xpows);
        ll hash2 = get_substring_hash(H, b, l, MOD, X, xpows);
        cout << (hash1 == hash2 ? "Yes\n" : "No\n");
    }

    return 0;
}
