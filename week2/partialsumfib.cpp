#include <iostream>
using namespace std;

int get_pisano_period(int m) {
    int a = 0, b = 1, c;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return -1;
}

int get_fibonacci_mod(long long n, int m) {
    int period = get_pisano_period(m);
    n %= period;

    int a = 0, b = 1, c;
    if (n <= 1) return n;
    for (long long i = 2; i <= n; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    long long m, n;
    cin >> m >> n;
    int sum = (get_fibonacci_mod(n + 2, 10) - get_fibonacci_mod(m + 1, 10) + 10) % 10;
    cout << sum << "\n";
}
