#include <iostream>
#include <vector>
using namespace std;
vector <vector<int> > G;
int par[1000005][25];
int dep[1000005];
void dfs(int u){   
    for(int v : G[u]){
        if(par[v][0] == -1){
            par[v][0] = u;
            dep[v] = dep[u]+1;
            dfs(v);
        }
    }
}
int LCA(int a, int b){
    if(dep[a] > dep[b]) swap(a,b);
    // cout << "!!" << a << ' ' << b << '\n';
    int d = dep[b]-dep[a];
    for(int j = 24;j >= 0;j--){
        if((1 << j) <= d){
            b = par[b][j];
            d -= (1<<j);
        }
    }
    //cout << "Hi " << a << ' ' << b << '\n';
    if(a == b) {
        return a;
    }
    for(int j = 24;j >= 0;j--){
        if(par[a][j] != par[b][j]){
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}
int main(){
    int n, q;
    cin >> n >> q;
    G.resize(n);
    for(int i = 0;i < n;i++){
        par[i][0] = -1;
    }
    for(int i = 0;i < n-1;i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    par[0][0] = 0;
    dep[0] = 0;
    dfs(0);
    for(int j = 1;j < 25;j++){
        for(int i = 0;i < n;i++){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << LCA(a,b)+1 << '\n';
    }
}