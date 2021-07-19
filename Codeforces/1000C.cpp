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
#define sz(a) (int)a.size()
using namespace std;
const int mxn = 2e5+5;
ll ans[mxn];
void solve(){
    int n;
    cin >> n;
    vector <pair<ll,ll> > a;
    for(int i = 0;i < n;i++){
        ll x, y;
        cin >> x >> y;
        a.pb({x,1});
        a.pb({y+1,-1});
    }
    a.pb({(ll)1e18,0});
    sort(a.begin(), a.end());
    ll now = 0, x = 0;
    for(int i = 0;i < sz(a);i++){
        ll l = a[i].first;
        ll s = a[i].second;
        ans[now] += l-x;
        now += s;
        x = l;
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << " \n"[i == n];
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}