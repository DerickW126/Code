#include <iostream>
#include <queue>
using namespace std;
using pli = pair<long long, int>;
const long long INF = 1e18;
vector <vector<long long> > Dijkstra(vector<vector<pair<int,int> > > G, int source, int k){ /* <to,weight> */
    int n = G.size();
    vector <vector<long long> > ans(n+1);
    priority_queue <pli, vector<pli >, greater<pli> > pq; /* <distance, index> */
    pq.push({0,source});
    while(!pq.empty()){
        long long dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(ans[u].size() >= k) continue;
        ans[u].push_back(dist); 
        for(int i = 0;i < G[u].size();i++){
            int v = G[u][i].first;
            int w = G[u][i].second;
            pq.push({dist + w, v});
        }
    }
    return ans; 
}
int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int> > >G(n+1);
    for(int i = 0;i < m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b,w});
        //G[b].push_back({a,w});
    }
    vector <vector<long long> >ans = Dijkstra(G,1,k);
    for(int i = 0;i < ans[n].size();i++){
        cout << ans[n][i] << ' ';
    }
    cout << endl;
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
