#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> cntl(n+1), cntr(n+1);
    for(int i = 0;i < n;i++){
        int x; cin >> x;
        if(i < l) cntl[x]++;
        else cntr[x]++;
    }
    // 1 1 2 2 2 2
    for(int i = 1;i <= n;i++){
        int mn = min(cntl[i], cntr[i]);
        cntl[i] -= mn;
        cntr[i] -= mn;
        l -= mn;
        r -= mn;
    }
    if(l < r){
        swap(cntl, cntr);
        swap(l,r);
    } 
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int diff = l-r;
        int extra = cntl[i]/2;
        int tmp = min(extra*2, diff);
        ans += tmp/2;
        l -= tmp;
    }
    ans += (l-r)/2+(l+r)/2;
    cout << ans << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}