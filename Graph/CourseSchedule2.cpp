#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector<int> > G;
int vis[100005];
bool flag = true;
vector <int> ans;
void dfs(int i){
    if(vis[i] == 1){
        flag = false;
        return;
    } else if(vis[i] == 2) {
        return;
    } else {
        vis[i] = 1;
        for(int x : G[i]){
            dfs(x);
        }
        ans.push_back(i);
        vis[i] = 2;
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
    }
    for(int i = 1;i <= n;i++){
        if(!vis[i]) dfs(i);
    }
    if(!flag) cout << "IMPOSSIBLE\n";
    else {
        reverse(ans.begin(), ans.end());
        for(int x : ans) cout << x << ' ';
        cout << '\n';
    }
}