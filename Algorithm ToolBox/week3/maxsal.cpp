#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isGreaterOrEqual(const string& a, const string& b) {
    return a + b > b + a;
}

string largest_number(vector<string>& numbers) {
    sort(numbers.begin(), numbers.end(), isGreaterOrEqual);
    string result;
    for (const string& num : numbers)
        result += num;

    // Remove leading zeros
    while (result.length() > 1 && result[0] == '0') result.erase(0, 1);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; ++i) cin >> numbers[i];
    cout << largest_number(numbers) << endl;
    return 0;
}
