#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int par[10005];
int root;
struct Edge{
    int u, v, weight;
};
bool cmp(Edge a, Edge b){
    return a.weight < b.weight;
}
int find(int x){
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    root--;
    par[x] = y; 
}
long long mst(vector <Edge> edges, int n){
    long long ans = 0;
    sort(edges.begin(),edges.end(),cmp);
    for(int i = 0;i < edges.size();i++){
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if(u != v){
            merge(u,v);
            ans += edges[i].weight;
        }
    }
    if(root != 1) return -1;
    else return ans;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m){
        root = n;
        for(int i = 0;i < n;i++){
            par[i] = -1;
        }
        vector <Edge> edges;
        for(int i = 0;i < m;i++){
            int a, b, w;
            cin >> a >> b >> w;
            edges.push_back({a,b,w});
        }
        cout << mst(edges,n) << '\n';
    }
}