#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 2e5;
vector <vector<int> > G;
bool vis[MAXN];
int dis[MAXN];
int pre[MAXN];
void bfs(int s){
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 1;
    pre[s] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int x : G[u]){
            if(!vis[x]){
                vis[x] = true;
                q.push(x);
                dis[x] = dis[u]+1;
                pre[x] = u;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs(1);
    if(dis[n] == 0){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << dis[n] << '\n';
    vector <int> ans;
    int r = n;
    while(pre[n] != -1){
        ans.push_back(pre[n]);
        n = pre[n];
    }
    for(int i = ans.size()-1;i >= 0;i--){
        cout << ans[i] << ' ';
    }
    cout << r << '\n';
}