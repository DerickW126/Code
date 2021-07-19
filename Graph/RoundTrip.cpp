#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector <vector <int> > G;
vector <int> par;
vector <int> ans;
vector <int> c;
set <pair<int,int> > s;
bool flag;
void dfs(int i, int parent){
    //if(ans.size()) return;
    c[i] = 1;
    par.push_back(i);
    for(int x : G[i]){
        if(x == parent) continue;
        if(c[x] == 0) {
            dfs(x, i);
            //if(ans.size()) return;
        } else if(c[x] == 1 && !flag){
            int j;
            for(j = 0;j < par.size() && par[j] != x;){
                j++;
            }
            for(int idx = j;idx < par.size();idx++){
                ans.push_back(par[idx]);
            }
            flag = true;
        } 
    }
    par.pop_back();
    c[i] = 2;
}
/*
void check(vector <int> &ans){
    for(int i = 1;i < ans.size();i++){
        if(!s.count({ans[i], ans[i-1]})){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
*/
int main(){
    int n, m;
    cin >> n >> m;
    G.resize(n);
    c.resize(n);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
        s.insert({a,b});
        s.insert({b,a});
    }
    for(int i = 0;i < n;i++){
        if(c[i] == 2) continue;
        dfs(i, -1);
        if(ans.size()){
            // check(ans);
            cout << ans.size()+1 << '\n';
            for(int x : ans){
                cout << x+1 << ' ';
            }
            cout << ans[0]+1 << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}