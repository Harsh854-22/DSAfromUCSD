#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    char type;
    int position;

    Bracket(char type, int position) : type(type), position(position) {}
    bool Match(char c) {
        return (type == '[' && c == ']') || (type == '{' && c == '}') || (type == '(' && c == ')');
    }
};

int main() {
    string text;
    cin >> text;
    stack<Bracket> opening_brackets_stack;

    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position + 1));
        } else if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty() || !opening_brackets_stack.top().Match(next)) {
                cout << position + 1 << endl;
                return 0;
            }
            opening_brackets_stack.pop();
        }
    }

    if (!opening_brackets_stack.empty()) {
        cout << opening_brackets_stack.top().position << endl;
    } else {
        cout << "Success" << endl;
    }

    return 0;
}
