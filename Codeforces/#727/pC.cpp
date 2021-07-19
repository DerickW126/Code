#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cstring>
#include <climits>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k, x;
    cin >> n >> k >> x;
    vector <ll> a(n);
    for(ll &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector <ll> v;
    for(int i = 1;i < n;i++){
        ll diff = abs(a[i]-a[i-1]);
        if(diff > x){
            v.push_back((diff+x*2-1)/(x*2));
        }
    }
    sort(v.begin(), v.end());
    int ans = v.size()+1;
    for(int i = 0;i < v.size();i++){
        if(k >= v[i]){
            k -= v[i];
            ans--;
        }
    }
    cout << ans << '\n';
}