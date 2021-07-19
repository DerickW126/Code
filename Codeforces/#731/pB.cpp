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
    string s;
    cin >> s;
    int n = s.size();
    int cnt[26] = {};
    int idx = -1;
    for(int i = 0;i < n;i++){
        cnt[s[i]-'a']++;
        if(s[i] == 'a') idx = i;
    }
    for(int i = 0;i < n;i++){
        if(!cnt[i]) {
            cout << "NO\n";
            return;
        }
    }
    if(idx == -1) {
        cout << "NO\n";
        return;
    }
    int l = idx, r = idx;
    int cur = 0;
    while(l >= 0 && r < n && n > 1){
        if(s[l-1]-'a' != cur+1 && s[r+1]-'a' != cur+1) break;
        if(s[l-1]-'a' == cur+1){
            l--, cur++;
        }
        if(s[r+1]-'a' == cur+1){
            r++, cur++;
        }
        if(cur == n-1) break;
    }
    if(cur == n-1) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}