#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, x;
    cin >> n >> x;
    vector <long long> c(n), dp(x+1,INT_MAX);
    for(long long &a : c) cin >> a;
    dp[0] = 0;
    for(int i = 1;i <= x;i++){
        for(int j = 0;j < n;j++){
            if(i-c[j] >= 0){
                dp[i] = min(dp[i], dp[i-c[j]]+1);
            }
        }
    }
    if(dp[x] == INT_MAX) cout << "-1\n";
    else cout << dp[x] << '\n';
}