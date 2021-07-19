#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge{
    int u, v, w;
};
vector <Edge> G;
const long long INF = 1e18;
vector <vector <int> > D1, D2;
vector <int> vis1;
vector <int> vis2;
void dfs1(int i){
    if(vis1[i]) return;
    vis1[i] = true;
    for(int x : D1[i]){
        dfs1(x);
    }
}
void dfs2(int i){
    if(vis2[i]) return;
    vis2[i] = true;
    for(int x : D2[i]){
        dfs2(x);
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vis1.resize(n+1);
    vis2.resize(n+1);
    D1.resize(n+1);
    D2.resize(n+1);
    for(int i = 0;i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        D1[a].push_back(b);
        D2[b].push_back(a);
        G.push_back((Edge){a,b,-w});
    }
    dfs1(1);
    dfs2(n);
    vector <long long> d(n+1, INF);
    d[1] = 0;
    for(int i = 0;i <= n;i++){
        bool flag = false;
        for(int j = 0;j < G.size();j++){
            int u = G[j].u;
            int v = G[j].v;
            int w = G[j].w;
            if(!vis1[u] || !vis2[u]) continue;
            if(d[u]+w < d[v]){
                d[v] = d[u]+w;
                flag = true;
            }
        }
        if(flag && i == n){
            cout << "-1\n";
            return 0;
        }
    }
    cout << -d[n] << '\n';
}