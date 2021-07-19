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
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int &x : a) cin >> x;
    vector <int> dp(n);
    vector <int> v;
    dp[0] = 1;
    v.pb(a[0]);
    int l = 1;
    for(int i = 1;i < n;i++){
        if(a[i] > v.back()){
            v.pb(a[i]);
            l++;
            dp[i] = l;
        } else {
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[idx] = a[i];
            dp[i] = idx+1;
        }
    }
    cout << l << '\n';
}