#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll X = 263;

ll poly_hash(const string& s) {
    ll hash = 0;
    for (int i = s.length() - 1; i >= 0; --i)
        hash = (hash * X + s[i]) % MOD;
    return hash;
}

vector<ll> precompute_hashes(const string& text, int pattern_len) {
    int n = text.length();
    vector<ll> H(n - pattern_len + 1);
    string s = text.substr(n - pattern_len, pattern_len);
    H[n - pattern_len] = poly_hash(s);

    ll y = 1;
    for (int i = 0; i < pattern_len; i++)
        y = (y * X) % MOD;

    for (int i = n - pattern_len - 1; i >= 0; --i) {
        H[i] = (X * H[i + 1] + text[i] - y * text[i + pattern_len] % MOD + MOD) % MOD;
    }

    return H;
}

int main() {
    string pattern, text;
    cin >> pattern >> text;
    int p_len = pattern.size();
    ll p_hash = poly_hash(pattern);
    vector<ll> H = precompute_hashes(text, p_len);

    for (int i = 0; i <= text.size() - p_len; ++i) {
        if (H[i] == p_hash && text.substr(i, p_len) == pattern)
            cout << i << " ";
    }

    return 0;
}
