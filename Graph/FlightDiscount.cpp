#include <iostream>
#include <queue>
using namespace std;
using pli = pair<long long, int>;
const long long INF = 1e18;
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
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int> > >G(n+1);
    vector<vector<pair<int,int> > >B(n+1);
    for(int i = 0;i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        B[b].push_back({a,w});
    }
    vector <long long> ans1 = Dijkstra(G,1);
    vector <long long> ans2 = Dijkstra(B,n);
    long long ans = INF;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < G[i].size();j++){
            int u = i;
            int v = G[i][j].first;
            long long x = G[i][j].second/2;
            ans = min(ans, ans1[u]+ans2[v]+x);
        }
    }
    cout << ans << '\n';
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
