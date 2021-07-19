#include <iostream>
#include <queue>
using namespace std;
using pli = pair<long long, int>;
const long long INF = 1e9+1;
const int MOD = 1e9+7;
int dp[100005], mx[100005], mn[100005];
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
            dp[v] = (dp[u]%MOD + dp[v]%MOD)%MOD;
            mx[v] = max(mx[v], mx[u]+1);
            mn[v] = min(mn[v], mn[u]+1);
            pq.push({dist + w, v});
        }
    }
    return ans; 
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int> > >G(n+1);
    for(int i = 0;i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        //G[b].push_back({a,w});
    }
    dp[1] = 1;
    for(int i = 1;i <= n;i++){
        mn[i] = INF;
        mx[i] = 0;
    }
    vector <long long> ans = Dijkstra(G,1);
    cout << ans[n] << ' ' << dp[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
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
