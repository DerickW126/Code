#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;
vector <vector<int> > G;
vector <bool> vis;
vector <int> dp;
void dfs(int i){
    if(vis[i]) {
        return;
    } else {
        vis[i] = true;
        for(int x : G[i]){
            dfs(x);
            dp[i] = max(dp[i], dp[x]+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    dp = vector <int>(n+1,-INF);
    vis.resize(n+1);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    dp[n] = 1;
    dfs(1);
    if(dp[1] < 0) cout << "IMPOSSIBLE\n";
    else {
        cout << dp[1] << '\n';
        int i = 1;
        while(i != n){
            cout << i << ' ';
            for(int x : G[i]){
                if(dp[x]+1 == dp[i]){
                    i = x;
                    break;
                }
            }
        }
        cout << n << '\n';
    }
}