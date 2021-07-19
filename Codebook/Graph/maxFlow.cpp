#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge{
    int u, v, cap, rest;
};
vector <Edge> edges;
vector <vector<int> > G;
vector <bool> vis;
void init(int n){
    edges.clear();
    vis = vector <bool>(n+1);
    G = vector <vector<int> >(n+1);
}
void add_edge(int u, int v, int cap){
    edges.push_back({u,v,cap,cap});
    edges.push_back({v,u,0,0});
    G[u].push_back(edges.size()-2);
    G[v].push_back(edges.size()-1);
}
int dfs(int u, int t, int a){
    if(u == t) return a;
    else if(vis[u]) return 0;
    else {
        vis[u] = 1;
        int flow = 0;
        for(int i = 0;i < G[u].size();i++){
            int e = G[u][i];
            if(edges[e].rest > 0){
                int f = dfs(edges[e].v,t,min(a,edges[e].rest));
                if(f > 0){
                    edges[e].rest -= f;
                    edges[e^1].rest += f;
                    flow += f;
                    a -= f;
                    if(a == 0) break;
                }
            }
        }
        return flow;
    }
}
int Ford_Fulkerson(int s, int t){
    int ans = 0;
    while(1){
        fill(vis.begin(), vis.end(),0);
        int f = dfs(s,t,INT_MAX);
        if(f == 0) break;
        else {
            ans += f;
        }
    }
    return ans;
}
int main(){
    int n;
    int cnt = 0;
    while(cin >> n){
        cnt++;
        if(n == 0) break;
        int s, t, c;
        cin >> s >> t >> c;
        init(n);
        for(int i = 0;i < c;i++){
            int u, v, cap;
            cin >> u >> v >> cap;
            add_edge(u,v,cap);
            add_edge(v,u,cap);
        }
        cout << "Network " << cnt << '\n';
        cout << "The bandwidth is " << Ford_Fulkerson(s,t) << ".\n";
    }
}