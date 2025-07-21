#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>> prices;
vector<vector<int>> adj;
vector<int> mt;
vector<bool> used;

bool tryKuhn(int v){
    if(used[v]) return false;
    used[v]=true;
    for(int u: adj[v]){
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
    cin >> n >> k;
    prices.assign(n, vector<int>(k));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin >> prices[i][j];
    adj.assign(n, {});
    auto less_all = [&](int i, int j){
        for(int t=0;t<k;t++){
            if(prices[i][t] >= prices[j][t]) return false;
        }
        return true;
    };
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(less_all(i,j))
                adj[i].push_back(j);
    mt.assign(n, -1);
    int match=0;
    for(int v=0;v<n;v++){
        used.assign(n,false);
        if(tryKuhn(v)) match++;
    }
    cout << n - match << "\n";
    return 0;
}
