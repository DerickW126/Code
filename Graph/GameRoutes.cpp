#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9+7;
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
            dp[i] += dp[x] % MOD;
            dp[i] %= MOD;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    G.resize(n+1);
    dp = vector <int>(n+1);
    vis.resize(n+1);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    dp[n] = 1;
    dfs(1);
    cout << dp[1] << '\n';
}