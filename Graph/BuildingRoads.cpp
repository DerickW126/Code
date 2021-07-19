#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2e5;
vector <vector <int> > G;
bool vis[MAXN];
int dis[MAXN];
void dfs(int i){
    if(vis[i]) return;
    vis[i] = true;
    for(int x : G[i]) {
        dfs(x);
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
    int cnt = 0;
    vector <int> ans;
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
            if(i == 1) continue;
            ans.push_back(i);
        }
    }
    cout << cnt-1 << '\n';
    for(int i = 0;i < ans.size() ;i++){
        cout << "1 " << ans[i] << ' ';
    }
    cout << '\n';
}