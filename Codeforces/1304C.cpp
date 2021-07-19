#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#include <set>
#define ll long long
using namespace std;
struct Person{
    int t, l, r;
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector <Person> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i].t >> a[i].l >> a[i].r;
    }
    int time = 0, mx = m, mn = m;
    for(int i = 0;i < n;i++){
        mx += a[i].t-time;
        mn -= a[i].t-time;
        if(mx < a[i].l || mn > a[i].r){
            cout << "NO\n";
            return;
        }
        mx = min(a[i].r, mx);
        mn = max(a[i].l, mn);
        time = a[i].t;
    }
    cout << "YES\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}