#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, string> phonebook;

    while (n--) {
        string type;
        cin >> type;

        if (type == "add") {
            int number;
            string name;
            cin >> number >> name;
            phonebook[number] = name;
        } else if (type == "del") {
            int number;
            cin >> number;
            phonebook.erase(number);
        } else if (type == "find") {
            int number;
            cin >> number;
            if (phonebook.count(number))
                cout << phonebook[number] << "\n";
            else
                cout << "not found\n";
        }
    }

    return 0;
}
