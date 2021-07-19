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
    int a1, a2, b1, b2, f1, f2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    cin >> f1 >> f2;
    int ans = abs(b1-a1)+abs(b2-a2);
    if((b1 == a1 && f1 == b1 && f2 > min(a2,b2) && f2 < max(a2,b2)) || (b2 == a2 && f2 == b2 && f1 > min(a1,b1) && f1 < max(a1,b1))) ans += 2;
    cout << ans << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}