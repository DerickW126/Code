#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#define ll long long
using namespace std;
void solve(){
    int n, x, t;
    cin >> n >> x >> t;
    ll ans = 0;
    int a = t/x;
    if(n-1 <= a){
        ans += (ll)((n-1)*(ll)(n)/2);
    } else {
        ans += (ll)a*(n-a);
        ans += (ll)((a-1)*(ll)(a)/2);
    }
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}