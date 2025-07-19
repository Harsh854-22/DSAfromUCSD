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

int fibonacci_mod(long long n, int m) {
    int period = get_pisano_period(m);
    n %= period;

    if (n <= 1) return n;
    int a = 0, b = 1;
    for (long long i = 2; i <= n; i++) {
        int c = (a + b) % m;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    long long n;
    int m;
    cin >> n >> m;
    cout << fibonacci_mod(n, m) << "\n";
}
