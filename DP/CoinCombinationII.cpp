#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9+7;
int main(){
	int n, x; cin >> n >> x;
	vector <long long> dp(x+1);
	vector <int> coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int weight = 1; weight <= x; weight++) {
			if(weight - coins[i] >= 0) {
				dp[weight] += dp[weight - coins[i]];
				dp[weight] %= MOD;
			}
		}
	}
	cout << dp[x] << '\n';	
}
