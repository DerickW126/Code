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
using namespace std;
const int mxn = 1500001;
int cnt[mxn];
void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    map <int,int> mp;
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(a[i] > 1){
            if(cnt[a[i]-1] == 0){
                cnt[a[i]-1]++;
                ans++;
            } else if(cnt[a[i]] == 0){
                cnt[a[i]]++;
                ans++;
            } else if(cnt[a[i]+1] == 0){
                cnt[a[i]+1]++;
                ans++;
            }
        } else {
            if(cnt[a[i]] == 0){
                cnt[a[i]]++;
                ans++;
            } else if(cnt[a[i]+1] == 0){
                cnt[a[i]+1]++;
                ans++;
            }
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