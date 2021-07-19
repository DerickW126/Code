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
ll gcd(ll a, ll b){
    return (b == 0 ? a : gcd(b, a % b));
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
void solve(){
    ll i = 2;
    ll l = 1;
    while(l <= 1e16){
        l = lcm(l, i);
        i++;
    }
    cout << i << ' ';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(t--) solve();
}