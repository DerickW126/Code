#include <iostream>
#include <priority_queue>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector <int> u(n);
    int cnt = 0;
    for(int i = 0;i < n;i++){
        cin >> u[i];
        u[i]--;
        cnt++;
    }
    vector <vector<int> > v(cnt);
    vector <vector<int> > pre(cnt);
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        v[u[i]].push_back(x);
    }
    for(int i = 0;i < cnt;i++){
        sort(v[i].begin(), v[i].end());
        pre[i][0] = v[i][0];
        for(int j = 1;j < v[i].size();j++){
            pre[i][j] = pre[i][j-1] + v[i][j];
        }
    }
    for(int k = 1;k <= n;k++){
        
    }
    cout << sum << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}