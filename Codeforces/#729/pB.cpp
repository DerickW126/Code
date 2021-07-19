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
    int n, a, b;
    cin >> n >> a >> b;
    if(a == 1){
        if((n-1) % b == 0) cout << "Yes\n";
        else cout << "No\n";
    } else {
        vector <int> nums;
        ll tmp = 1;
        while(tmp <= 1e9){
            nums.push_back(tmp);
            tmp *= a;
        }
        for(int i = 0;i < nums.size();i++){
            if(n-nums[i] < 0) break;
            if((n-nums[i]) % b == 0){
                cout << "Yes\n";
                return;
            }
        }
        cout << "No\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}