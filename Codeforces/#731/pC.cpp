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
    int k, n, m;
    cin >> k >> n >> m;
    vector <int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int cur = k;
    vector <int> ans;
    int l = 0, r = 0;
    while(l < n || r < m){
        if(a[l] > 0 && l < n && a[l] <= cur){
            ans.pb(a[l]);
            l++;
            continue;
        }
        if(b[r] > 0 && r < m && b[r] <= cur){
            ans.pb(b[r]);
            r++;
            continue;
        }
        if(a[l] == 0 && l < n) {
            cur++;
            l++;
            ans.pb(0);
            continue;
        } 
        if(b[r] == 0 && r < m){
            cur++;
            r++;
            ans.pb(0);
            continue;
        }
        if(a[l] > 0 && l < n){
            if(a[l] > cur){
                cout << "-1\n";
                return;
            } else {
                ans.pb(a[l]);
                l++;
                continue;
            }
        }
        if(b[r] > 0 && r < m){
            if(b[r] > cur){
                cout << "-1\n";
                return;
            } else {
                ans.pb(b[r]);
                r++;
                continue;
            }
        }
    }
    for(int x : ans){
        cout << x << ' ';
    }
    cout << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}