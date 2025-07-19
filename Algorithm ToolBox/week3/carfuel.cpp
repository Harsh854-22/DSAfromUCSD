#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
    stops.push_back(dist);
    int num_refills = 0, current = 0, last_refill = 0;

    for (int i = 0; i < stops.size(); ++i) {
        if (stops[i] - current > tank) {
            if (current == last_refill) return -1;
            last_refill = current;
            ++num_refills;
        }
        if (stops[i] - last_refill <= tank)
            current = stops[i];
    }

    return num_refills;
}

int main() {
    int d, m, n;
    cin >> d >> m >> n;
    vector<int> stops(n);
    for (int i = 0; i < n; ++i) cin >> stops[i];
    cout << compute_min_refills(d, m, stops) << endl;
    return 0;
}
