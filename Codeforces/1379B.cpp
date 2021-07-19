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
    int l, r;
    ll m;
    cin >> l >> r >> m;
    for(int i = l;i <= r;i++){
        if(m >= i && (m%i) <= r-l){
            cout << i << ' ' << l+(m%i) << ' ' << l << '\n';
            return;
        } 
        if(i-m%i <= r-l){
            cout << i << ' ' << l << ' ' << l+i-m%i << '\n';
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}