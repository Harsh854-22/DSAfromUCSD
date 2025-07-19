#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> main_stack, max_stack;

void push(int value) {
    main_stack.push(value);
    if (max_stack.empty() || value >= max_stack.top())
        max_stack.push(value);
}

void pop() {
    if (!main_stack.empty()) {
        if (main_stack.top() == max_stack.top())
            max_stack.pop();
        main_stack.pop();
    }
}

int get_max() {
    return max_stack.top();
}

int main() {
    int n;
    cin >> n;
    string command;
    
    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "push") {
            int value;
            cin >> value;
            push(value);
        } else if (command == "pop") {
            pop();
        } else if (command == "max") {
            cout << get_max() << endl;
        }
    }

    return 0;
}
