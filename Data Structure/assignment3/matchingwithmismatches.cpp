#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int countMismatches(const string& pattern, const string& text, int start) {
    int mismatches = 0;
    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] != text[start + i]) mismatches++;
        if (mismatches > 1) return 2; // early exit
    }
    return mismatches;
}

int main() {
    string pattern, text;
    cin >> pattern >> text;

    vector<int> result;
    int p_len = pattern.size();
    int t_len = text.size();

    for (int i = 0; i <= t_len - p_len; i++) {
        if (countMismatches(pattern, text, i) <= 1)
            result.push_back(i);
    }

    for (int i : result)
        cout << i << " ";
    cout << "\n";

    return 0;
}
