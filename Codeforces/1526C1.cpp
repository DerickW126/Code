#include <iostream>
using namespace std;
const int MAXN=2050;

long long dp[MAXN][MAXN],a[MAXN];
int main() {
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) {
        cin >> a[i];
        dp[0][i] = -1;
    }
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			dp[i][j] = dp[i-1][j];
			if(dp[i-1][j-1] != -1 && dp[i-1][j-1]+a[i] >= 0) {
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+a[i]);
            }
		}
    }   
	for(int i = n;i >= 1;i--){
		if(dp[n][i] != -1) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "0\n";
}