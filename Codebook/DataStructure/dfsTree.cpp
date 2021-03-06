#include <iostream>
#include <vector>
using namespace std;
int timestamp = 1;
vector <vector <int> > G;
vector <int> par;
vector <int> ans;
vector <int> c;
vector <int> tin, tout;
void dfs(int i){
    // if(ans.size()) return;
    c[i] = 1;
    par.push_back(i);
    tin[i] = timestamp++;
    //for(int x : par) cout << x+1 << ' ';
    //cout << '\n';
    for(int x : G[i]){
        if(c[x] == 0) {
            cout << "Tree Edge: " << i << ' ' << x << '\n';
            dfs(x);
        }
        else if(c[x] == 1) {
            cout << "Back Edge: " << i << ' ' << x << '\n';
        } else {
            if(tin[x] > tin[i]){
                cout << "Forwarding Edge: " << i << ' ' << x << '\n';
            } else {
                cout << "Crossing Edge: " << i << ' ' << x << '\n';
            }
        }
    }
    c[i] = 2;
    par.pop_back();
    tout[i] = timestamp++;
}
int main(){
    int n, m;
    cin >> n >> m;
    G.resize(n);
    c.resize(n);
    tin.resize(n);
    tout.resize(n);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
    }
    for(int i = 0;i < n;i++){
        if(c[i] == 2) continue;
        dfs(i);
        if(ans.size()){
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