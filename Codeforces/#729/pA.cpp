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
const int mod = 1e9+7;
void solve(){
    ll odd, even, six;
    cin >> odd >> even >> six;
    cout << odd*2+(even-six)*3+4*six/2+5*six/2%mod << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}