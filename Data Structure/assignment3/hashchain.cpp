#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

const int multiplier = 263;
const int prime = 1000000007;

int hash_func(const string& s, int bucket_count) {
    long long hash = 0;
    for (int i = s.size() - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
    return hash % bucket_count;
}

int main() {
    int bucket_count, n;
    cin >> bucket_count >> n;
    vector<list<string>> hash_table(bucket_count);

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            string s;
            cin >> s;
            int index = hash_func(s, bucket_count);
            auto& chain = hash_table[index];
            if (find(chain.begin(), chain.end(), s) == chain.end())
                chain.push_front(s);
        } else if (cmd == "del") {
            string s;
            cin >> s;
            int index = hash_func(s, bucket_count);
            auto& chain = hash_table[index];
            chain.remove(s);
        } else if (cmd == "find") {
            string s;
            cin >> s;
            int index = hash_func(s, bucket_count);
            auto& chain = hash_table[index];
            cout << (find(chain.begin(), chain.end(), s) != chain.end() ? "yes\n" : "no\n");
        } else if (cmd == "check") {
            int i;
            cin >> i;
            for (auto& s : hash_table[i])
                cout << s << " ";
            cout << "\n";
        }
    }

    return 0;
}
