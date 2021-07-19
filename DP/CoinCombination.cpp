#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9+7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x; 
    vector <long long> c(n), dp(x+1);
    for(long long &u : c) {
        cin >> u;
    }
    dp[0] = 1;
    for(int i = 1;i <= x;i++){
        for(int j = 0;j < n;j++){
            if(i-c[j] >= 0){
                dp[i] += (dp[i-c[j]])%MOD;
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}