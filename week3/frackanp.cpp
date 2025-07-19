#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    double value, weight;
    double value_per_weight;
};

bool compare(Item a, Item b) {
    return a.value_per_weight > b.value_per_weight;
}

double get_optimal_value(int n, double capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double total_value = 0.0;

    for (int i = 0; i < n && capacity > 0; ++i) {
        double amount = min(capacity, items[i].weight);
        total_value += amount * items[i].value_per_weight;
        capacity -= amount;
    }

    return total_value;
}

int main() {
    int n;
    double capacity;
    cin >> n >> capacity;
    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
        items[i].value_per_weight = items[i].value / items[i].weight;
    }

    printf("%.10f\n", get_optimal_value(n, capacity, items));
    return 0;
}
