#include <bits/stdc++.h>
using namespace std;
struct Edge{int v, cap, rev;};
vector<vector<Edge>> G;
void addEdge(int u,int v,int c){
    G[u].push_back({v,c,(int)G[v].size()});
    G[v].push_back({u,0,(int)G[u].size()-1});
}

int maxflow(int s,int t){
    int flow=0, N=G.size();
    while(true){
        vector<int> level(N,-1), ptr(N,0), q(N);
        int qh=0, qt=0;
        level[s]=0; q[qt++]=s;
        while(qh<qt){
            int u=q[qh++];
            for(auto &e:G[u]){
                if(level[e.v]<0 && e.cap>0){
                    level[e.v]=level[u]+1;
                    q[qt++]=e.v;
                }
            }
        }
        if(level[t]<0) break;
        function<int(int,int)> dfs = [&](int u,int f){
            if(u==t) return f;
            for(int &cid=ptr[u]; cid<(int)G[u].size(); cid++){
                Edge &e=G[u][cid];
                if(e.cap>0 && level[e.v]==level[u]+1){
                    int pushed=dfs(e.v, min(f,e.cap));
                    if(pushed>0){
                        e.cap -= pushed;
                        G[e.v][e.rev].cap += pushed;
                        return pushed;
                    }
                }
            }
            return 0;
        };
        while(int pushed = dfs(s, INT_MAX))
            flow += pushed;
    }
    return flow;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; 
    cin>>n>>m;
    G.assign(n+1, {});
    for(int i=0,u,v,c;i<m;i++){
        cin>>u>>v>>c;
        addEdge(u,v,c);
    }
    cout << maxflow(1, n) << "\n";
    return 0;
}
