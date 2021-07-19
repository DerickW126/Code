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
void solve(){
    int n;
    cin >> n;
    vector <ll> a(n), b(n);
    for(ll &x : a) cin >> x;
    for(ll &x : b) cin >> x;
    vector <ll> pre(n);
    pre[0] = a[0]*b[0];
    for(int i = 1;i < n;i++){
        pre[i] = pre[i-1]+a[i]*b[i];
    }
    ll ans = pre[n-1];
    for(int c = 0;c < n;c++){
        ll cur = a[c]*b[c];
        for(int l = c-1, r = c+1;l >= 0 && r < n;l--,r++){
            cur += a[l]*b[r];
            cur += a[r]*b[l];
            if(l == 0) ans = max(ans, cur+(pre[n-1]-pre[r]));
            else ans = max(ans, cur+pre[l-1]+(pre[n-1]-pre[r]));
        }
        cur = 0;
        for(int l = c, r = c+1;l >= 0 && r < n;l--,r++){
            cur += a[l]*b[r];
            cur += a[r]*b[l];
            if(l == 0) ans = max(ans, cur+(pre[n-1]-pre[r]));
            else ans = max(ans, cur+pre[l-1]+(pre[n-1]-pre[r]));
        }
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--) solve();
}