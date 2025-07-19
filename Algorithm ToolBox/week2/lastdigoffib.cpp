#include <iostream>
using namespace std;

int fibonacci_last_digit(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = (a + b) % 10;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci_last_digit(n) << "\n";
}
