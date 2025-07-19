#include <iostream>
using namespace std;

int get_fibonacci_mod(int n, int m) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    int fn = get_fibonacci_mod(n, 10);
    int fn1 = get_fibonacci_mod(n + 1, 10);
    cout << (fn * fn1) % 10 << "\n";
}
