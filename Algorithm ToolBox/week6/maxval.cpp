#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long eval(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

pair<long long, long long> minAndMax(int i, int j, const vector<vector<long long>>& m, const vector<vector<long long>>& M, const vector<char>& ops) {
    long long minVal = LLONG_MAX;
    long long maxVal = LLONG_MIN;
    for (int k = i; k < j; ++k) {
        char op = ops[k];
        long long a = eval(M[i][k], M[k + 1][j], op);
        long long b = eval(M[i][k], m[k + 1][j], op);
        long long c = eval(m[i][k], M[k + 1][j], op);
        long long d = eval(m[i][k], m[k + 1][j], op);
        minVal = min({minVal, a, b, c, d});
        maxVal = max({maxVal, a, b, c, d});
    }
    return {minVal, maxVal};
}

long long getMaxValue(const string& exp) {
    vector<long long> digits;
    vector<char> ops;

    for (int i = 0; i < exp.size(); ++i) {
        if (i % 2 == 0)
            digits.push_back(exp[i] - '0');
        else
            ops.push_back(exp[i]);
    }

    int n = digits.size();
    vector<vector<long long>> m(n, vector<long long>(n, 0));
    vector<vector<long long>> M(n, vector<long long>(n, 0));

    for (int i = 0; i < n; ++i)
        m[i][i] = M[i][i] = digits[i];

    for (int s = 1; s < n; ++s) {
        for (int i = 0; i < n - s; ++i) {
            int j = i + s;
            auto [minVal, maxVal] = minAndMax(i, j, m, M, ops);
            m[i][j] = minVal;
            M[i][j] = maxVal;
        }
    }

    return M[0][n - 1];
}

int main() {
    string exp;
    cin >> exp;
    cout << getMaxValue(exp) << endl;
    return 0;
}
