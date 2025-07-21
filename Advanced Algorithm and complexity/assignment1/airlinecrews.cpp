#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> mt;
vector<bool> used;

bool tryKuhn(int v){
    if(used[v]) return false;
    used[v] = true;
    for(int u : adj[v]){
        if(mt[u] == -1 || tryKuhn(mt[u])){
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.assign(n, {});
    for(int i = 0; i < n; i++){
        for(int j = 0, x; j < m; j++){
            cin >> x;
            if(x) adj[i].push_back(j);
        }
    }
    mt.assign(m, -1);
    int matching = 0;
    for(int v = 0; v < n; v++){
        used.assign(n, false);
        if(tryKuhn(v)) matching++;
    }
    cout << matching << "\n";
    for(int crew = 0; crew < m; crew++){
        if(mt[crew] != -1){
            cout << mt[crew]+1 << " " << crew+1 << "\n";
        }
    }
    return 0;
}
