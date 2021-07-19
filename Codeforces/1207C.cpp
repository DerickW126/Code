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
const ll INF = 1e18;
ll dp[200001][2];
void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    dp[0][0] = b;
    dp[0][1] = INF;
    for(int i = 1;i <= n;i++){
        if(s[i] == '1' || s[i-1] == '1'){
            dp[i][0] = INF;
            dp[i][1] = min(dp[i-1][0]+a*2+b*2, dp[i-1][1]+a+b*2);
        } else {
            dp[i][0] = min(dp[i-1][0]+a+b, dp[i-1][1]+a*2+b);
            dp[i][1] = min(dp[i-1][0]+a*2+b*2, dp[i-1][1]+a+b*2);
        }
    }
    cout << dp[n][0] << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}