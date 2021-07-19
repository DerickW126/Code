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
int mp[8001];
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int &x : a) cin >> x;
    vector <int> pre(n);
    pre[0] = a[0];
    for(int i = 1;i <= n;i++){
        mp[i] = 0;
    }
    for(int i = 1;i < n;i++){
        pre[i] = pre[i-1]+a[i];
    } 
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            if(i == 0) {
                if(pre[j] <= n)mp[pre[j]]++;
            } else if(pre[j]-pre[i-1] <= n){
                mp[pre[j]-pre[i-1]]++;
            }
        }
    }  
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(mp[a[i]]) ans ++;
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