#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DisjointSet {
    vector<int> parent, rank, size;
    int max_size;

    DisjointSet(const vector<int>& sizes) {
        int n = sizes.size();
        parent.resize(n);
        rank.resize(n, 0);
        size = sizes;
        max_size = *max_element(sizes.begin(), sizes.end());
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (i != parent[i])
            parent[i] = find(parent[i]);  // Path compression
        return parent[i];
    }

    void merge(int destination, int source) {
        int real_dest = find(destination);
        int real_source = find(source);

        if (real_dest == real_source) return;

        if (rank[real_dest] < rank[real_source]) {
            parent[real_dest] = real_source;
            size[real_source] += size[real_dest];
            size[real_dest] = 0;
        } else {
            parent[real_source] = real_dest;
            size[real_dest] += size[real_source];
            size[real_source] = 0;
            if (rank[real_dest] == rank[real_source])
                rank[real_dest]++;
        }

        max_size = max(max_size, size[real_dest]);
        max_size = max(max_size, size[real_source]);
    }

    int getMaxSize() const {
        return max_size;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> sizes(n);
    for (int i = 0; i < n; i++)
        cin >> sizes[i];

    DisjointSet ds(sizes);

    for (int i = 0; i < m; i++) {
        int destination, source;
        cin >> destination >> source;
        ds.merge(destination - 1, source - 1);  // Adjusting for 0-based indexing
        cout << ds.getMaxSize() << "\n";
    }

    return 0;
}
