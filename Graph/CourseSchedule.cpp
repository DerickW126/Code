#include <iostream>
#include <queue>
#include <vector>
using namespace std;
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
    queue <int> q;
    for(int i = 1;i <= n;i++){
        if(in[i] == 0) q.push(i);
    }
    vector <int> ans;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for(int i : G[x]){
            in[i]--;
            if(in[i] == 0) q.push(i);
        }
    }
    if((int)ans.size() < n) cout << "IMPOSSIBLE\n";
    else {
        for(int x : ans){
            cout << x << ' ';
        }
        cout << '\n';
    }
}