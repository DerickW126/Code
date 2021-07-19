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
int cnt[100001], c[100001];
void solve(){
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0;i <= 100000;i++){
        c[i] = -1;
        cnt[i] = 0;
    }
    for(int i = 0;i < n;i++){
        cin >> a[i];
        b[i] = a[i];
        cnt[a[i]]++;  
    }
    sort(b.begin(), b.end());
    for(int i = 0;i < n;i++){
        if(cnt[a[i]] % 2 == 0) continue;
        int l = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        if(c[l] != -1) {
            if(c[l] == 1) c[l+1] = 0;
            else c[l+1] = 1;
        }
        if(abs(l-i) % 2 == 1) c[l] = 0;
        else c[l] = 1;
    }
    bool flag = true;
    bool ok = true;
    for(int i = 0;i < n;i++){
        if(cnt[a[i]] % 2 == 0) continue;
        if(c[i] == 0 && !ok) flag = false;
        if(c[i] == 1) ok = false;
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}