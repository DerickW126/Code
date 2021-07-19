#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1e9;
vector <vector<int> > G;
int in[100005];
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
    }
    for(int i = 1;i <= n;i++){
        for(int j : G[i]){
            in[j]++;
        }
    }
    vector <int> dp(n+1,-INF);
    vector <int> pre(n+1);
    queue <int> q;
    for(int i = 1;i <= n;i++){
        if(in[i] == 0) q.push(i);
    }
    dp[1] = 1;
    pre[1] = -1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i : G[x]){
            in[i]--;
            if(dp[x]+1 > dp[i]){
                dp[i] = dp[x]+1;
                pre[i] = x;
            }
            if(in[i] == 0) q.push(i);
        }
    }
    if(dp[n] < 0) cout << "IMPOSSIBLE\n";
    else {
        cout << dp[n] << '\n';
        int idx = n;
        vector <int> v;
        while(idx != -1){
            v.push_back(idx);
            idx = pre[idx];
        }
        reverse(v.begin(), v.end());
        for(int x : v) cout << x << ' ';
        cout << '\n';
    }
}