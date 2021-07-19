#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pli = pair<long long, int>;
const long long INF = 1e18;
const int MOD = 1e9+7;
vector <int> num, mx, mn;
int n, m;
vector <long long> Dijkstra(vector<vector<pair<int,int> > > G, int source){ /* <to,weight> */
    int n = G.size();
    vector <bool> vis(n+1,false);
    vector <long long> ans(n+1,INF);
    priority_queue <pli, vector<pli >, greater<pli> > pq; /* <distance, index> */
    pq.push({0,source});
    while(!pq.empty()){
        long long dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ans[u] = dist; 
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i].first;
            int w = G[u][i].second;
            pq.push({dist + w, v});
        }
    }
    return ans; 
}
vector <int> TopologicalSort(vector <vector <int> > D){
    vector <int> din((D.size()));
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < D[i].size();j++){
            din[D[i][j]]++;
        }
    }
    queue <int> q;
    for(int i = 1;i <= n;i++){
        if(din[i] == 0) q.push(i);
    }
    vector <int> ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int i = 0;i < D[x].size();i++){
            din[D[x][i]]--;
            if(din[D[x][i]] == 0) q.push(D[x][i]);
        }
    }
    return ans;
}
int main(){
    cin >> n >> m;
    vector<vector<pair<int,int> > >G(n+1);
    for(int i = 0;i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
    }
    vector <long long> ans = Dijkstra(G,1);
    vector<vector <int> > D(n+1);
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < G[i].size();j++){
            int u = G[i][j].first;
            int w = G[i][j].second;
            if(ans[u]-ans[i] == w){
                D[i].push_back(u);
            }
        }
    }
    vector <int> a = TopologicalSort(D);
    num.resize(n+1,0);
    mx.resize(n+1,0);
    mn.resize(n+1,n);
    num[1] = 1;
    mx[1] = 0;
    mn[1] = 0;
    vector <bool> vis(n+1);
    vis[1] = 1;
    for(int u : a){
        if(!vis[u]) continue;
        for(int v : D[u]){
            vis[v] = 1;
            num[v] = (num[v]+num[u])%MOD;
            mx[v] = max(mx[v], mx[u]+1);
            mn[v] = min(mn[v], mn[u]+1);
        }
    }
    cout << ans[n] << ' ' << num[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
}
/*
5 7 0
0 1 2
1 2 3 
2 3 5
2 4 4 
4 3 1 
3 4 2
4 1 2
*/
