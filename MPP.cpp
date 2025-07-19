#include <iostream>
#include <vector>
#include <algorithm>

int MPP(const std::vector<int>& numbers) {
    int max_p = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_p = std::max(max_p,
                numbers[first] * numbers[second]);
        }
    }

    return max_p;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MPP(numbers) << "\n";
    return 0;
}
