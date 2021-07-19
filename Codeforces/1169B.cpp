#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <set>
#include <cmath>
#define ll long long
#define pb push_back
using namespace std;
void print(vector <int> a){
    for(int i : a) cout << i << ' ';
    cout << '\n';
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector <pair<int,int> > pairs;
    vector <int> val(n);
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        pairs.pb({a,b});
    }
    vector <int> base = {pairs[0].first, pairs[0].second};
    for(int i = 0;i < base.size();i++){
        int x = base[i];
        int cnt = 0;
        int mx = 0;
        val.clear();
        val.resize(n);
        for(int j = 0;j < m;j++){
            int f = pairs[j].first;
            int s = pairs[j].second;
            if(f != x && s != x){
                val[f]++;
                val[s]++;
                cnt++;
                mx = max({mx, val[f], val[s]});
            }
        }
        if(mx == cnt){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--) solve();
}